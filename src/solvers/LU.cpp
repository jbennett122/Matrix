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



using namespace std;


void LU(int argc,char* argv[]){



	ifstream fs;
	ifstream fs2;
	fs.open(argv[1]);

	int i,j,k,m,n,p,kk,s,count,choice;
	double nums,sum,tolerance;
	double error;
	count=0;

	fs.clear();
	fs>>n>>m;


	double **A,**u,**l,*x,*old ;	//A D matrix
	double b[n];	//Right hand side of Ax=b
	double z[n];
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


		//create matrices A,l,u and import values
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


 p=0;

cout<<"test"<<endl;

 l[n][n]={0},u[n][n]={0},sum,b[n],z[n]={0},x[n]={0};


   //********** LU decomposition *****//
   for(k=1;k<=n;k++)
   {
       u[k][k]=1;
       for(i=k;i<=n;i++)
       {
           sum=0;
           for(p=1;p<=k-1;p++)
               sum+=l[i][p]*u[p][k];
           l[i][k]=A[i][k]-sum;
       }

       for(j=k+1;j<=n;j++)
       {
           sum=0;
           for(p=1;p<=k-1;p++)
               sum+=l[k][p]*u[p][j];
           u[k][j]=(A[k][j]-sum)/l[k][k];
       }
   }
   //******** Displaying LU matrix**********//
   cout<<endl<<endl<<"LU matrix is "<<endl;
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
           cout<<l[i][j]<<"  ";
       cout<<endl;
   }
   cout<<endl;
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
           cout<<u[i][j]<<"  ";
       cout<<endl;
   }

   //***** FINDING Z; LZ=b*********//

   for(i=1;i<=n;i++)
   {                                        //forward subtitution method
       sum=0;
       for(p=1;p<i;p++)
       sum+=l[i][p]*z[p];
       z[i]=(b[i]-sum)/l[i][i];
   }
   //********** FINDING X; UX=Z***********//

   for(i=n;i>0;i--)
   {
       sum=0;
       for(p=n;p>i;p--)
           sum+=u[i][p]*x[p];
       x[i]=(z[i]-sum)/u[i][i];
   }
   //*********** DISPLAYING SOLUTION**************//
   cout<<endl<<"Set of solution is"<<endl;
   for(i=1;i<=n;i++)
       cout<<endl<<x[i];

}


