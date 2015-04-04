/*
 * gaussSidel.cpp
 *
 *  Created on: Apr 4, 2015
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
#include <iomanip>


using namespace std;



void* gaussSeidel(int argc,char* argv[])
{


	ifstream fs;
		fs.open(argv[1]);

		int i,j,k,l,m,n,count,choice;
		double nums,sum,tolerance,U,L;;

		count=0;

		fs.clear();
		fs>>n>>m;


		double **A,**D,**C,*x,*old,*diff;	//A D matrix
		double b[n];	//Right hand side of Ax=b
		double ending=1.0/100000.0;

		srand (time(NULL));


	//initial guess
	//cout<<"Initial guess"<<endl;
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
	 	for (i=0; i < n; i++)
			{
			cout<<"|";
				for(j=0;j<m;j++){

				  cout<<" "<<setw(8)<<A[i][j]<<" ";
				}
			cout<<"|"<<endl;
			}


		//cout<<"entries in A matrix: "<<count<<endl;
		cout<<"RHS"<<endl;

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






old = new double [n];

count=0;
do{

	for(i=0;i<n;i++){

		old[i]=x[i];

			}

	for(int i=0; i<n; ++i)
		{
			sum = L = U = 0;
				//Sum lowerC
					for(int j = 0; j < i; ++j)
							{
								L = L + (A[i][j] * x[j]);
							}
					//Sum upperC
					for( int j = (i+1); j < m; ++j)
							{
								U= U + (A[i][j] * x[j]);
							}
					//Total for iteration
					sum = b[i] - L - U;

					//Update xk1[i]
					x[i] = sum / A[i][i];

		}

	tolerance=tolCheck(x, old, n);

count++;
}while(ending<tolerance);

cout<<"\nfinal"<<endl;

	for(i=0;i<n;i++){
					cout<<"|";
						cout<<" "<<setw(8)<<x[i]<<" ";
					cout<<"|"<<endl;
				}


}



