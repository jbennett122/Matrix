/*
 * LU.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: Justin
 */


#include <cmath>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>     /* srand, rand */
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>
#include <iomanip>
#include "../headers/operations.h"
#include "../headers/LU.h"
#include <iomanip>

#define ZERO 1.0E-20
#define true 1
#define false 0


using namespace std;




static void OUTPUT(int n, double **A, int ISW)
{
   int i, j, FLAG;

   cout<<"GENERAL LU FACTORIZATION"<<endl;
   if (ISW == 0)
      cout<<"The diagonal of L consists of all entries = 1.0"<<endl;
   else
      cout<<"The diagonal of U consists of all entries = 1.0"<<endl;
   cout<<"Entries of L below diagonal and entries of U above/on diagonal"<<endl;
   cout<<"- output by rows in overwrite format:"<<endl;
   for (i=1; i<=n; i++) {

	   cout<<"|";

      for (j=1; j<=n; j++){
    		cout<<" "<<setw(8)<<A[i-1][j-1];
      }
      cout<<"|"<<endl;
      }

   }



/* Absolute Value Function */
static double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}



void LU2(int argc,char* argv[]){



	ifstream fs;
	fs.open(argv[1]);

	int i,j,k,l,m,n,jj,kk,s,ss,count,choice;
	double nums,sum,tolerance;
	double error;
	count=0;

	fs.clear();
	fs>>n>>m;


	double **A,**D,**C,*x,*old,*diff;	//A D matrix
	double b[n];	//Right hand side of Ax=b
	double ending=1.0/10000.0;

	srand (time(NULL));


	//initial guess
		cout<<"\nInitial guess"<<endl;
		x=new double [n];
		for(i=0;i<n;i++){

			double v1 = rand() %200 -100;

			x[i]=v1;
		}
				for(i=0;i<n;i++){
						cout<<"|";
							cout<<" "<<setw(8)<<x[i]<<" ";
						cout<<"|"<<endl;
							}


		//create matrix and import values
			A = new double *[n];
			for (i=0; i < n; i++)
			{
				A[i]=new double [m];

				for(j=0;j<m;j++){

					fs>>nums;
					A[i][j]=nums;
					count++;

				}
			}

			cout<<"\nA matrix "<<endl;
		 	for (i=0; i < n; i++)
				{
				cout<<"|";
					for(j=0;j<m;j++){

					  cout<<" "<<setw(8)<<A[i][j]<<" ";
					}
				cout<<"|"<<endl;
				}


			//cout<<"entries in A matrix: "<<count<<endl;
			cout<<"\nRHS"<<endl;

			count =0;

		for(i=0;i<n;i++){

				fs>>nums;
				b[i]=nums;
				count++;
				}

			for (i=0; i < n; i++)
					{
					cout<<"|";
						cout<<" "<<setw(8)<<b[i]<<" ";
					cout<<"|"<<endl;
					}

      int ISW = 0,OK = true;
                /* ISW = 0 specifies that entris on diagonal of L are all ones */

      cout.setf(ios::fixed,ios::floatfield);
      cout.precision(2);

      for (i=1; i<=n; i++) x[i-1] = 1.0;
      /* STEP 1 */
      if (absval(A[0][0]) <= ZERO) OK = false;
      else {

         A[0][0] = A[0][0] / x[0];

         for (j=2; j<=n; j++) {
            if (ISW == 0) {
               /* first row of U */
               A[0][j-1] = A[0][j-1] / x[0];
               /* first column of L */
               A[j-1][0] = A[j-1][0] / A[0][0];
            }
            else {
               /* first row of U */
               A[0][j-1] = A[0][j-1] / A[0][0];
               /* first column of L */
               A[j-1][0] = A[j-1][0] / x[0];
            }
         }
         /* STEP 3 */
         m = n - 1;
         i = 2;
         while ((i <= m) && OK) {
            /* STEP 4 */
            kk = i - 1;
            s = 0.0;
            for (k=1; k<=kk; k++) s = s - A[i-1][k-1] * A[k-1][i-1];
            A[i-1][i-1] = ( A[i-1][i-1] + s ) / x[i-1];
            if (absval(A[i-1][i-1]) <= ZERO) OK = false;
            else {
               /* STEP 5 */
               jj = i + 1;
               for (j=jj; j<=n; j++) {
                  ss = 0.0;
                  s = 0.0;
                  for (k=1; k<=kk; k++) {
                     ss= ss - A[i-1][k-1] * A[k-1][j-1];
                     s = s - A[j-1][k-1] * A[k-1][i-1];
                  }
                  if (ISW == 0) {
                     /* Ith row of U */
                     A[i-1][j-1] = (A[i-1][j-1] + ss) / x[i-1];
                     /* Ith column of L */
                     A[j-1][i-1] = (A[j-1][i-1] + s) / A[i-1][i-1];
                  }
                  else {
                     /* Ith row of U */
                     A[i-1][j-1] = (A[i-1][j-1] + ss) / A[i-1][i-1];
                     /* Ith column of L */
                     A[j-1][i-1] = (A[j-1][i-1] + s) / x[i-1];
                  }
               }
            }
            i++;
         }
         if (OK) {
            /* STEP 6 */
            s = 0.0;
            for (k=1; k<=m; k++)  s = s - A[n-1][k-1] * A[k-1][n-1];
            A[n-1][n-1] = (A[n-1][n-1] + s) / x[n-1];
            /* If A(N-1,N-1) = 0 then A = LU but the matrix is singular.
               Process is complete, all entries of A have been
               determined. */
            /* STEP 7 */
            OUTPUT(n, A, ISW);
         }
      }

      if (!OK) cout<<"System has no unique solution"<<endl;

error=0;
      choices(count,n,x,error);


}

