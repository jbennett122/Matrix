/*
 * sor.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: hideo
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

void sor(int argc,char* argv[]){
	ifstream fs;
	fs.open(argv[1]);

	int i,j,k,l,m,n,count,choice;
	double nums, L,U,omega;
	double error;
	count=0;
	omega=1.15;
	fs.clear();
	fs>>n>>m;

	float sum,diff;

	double **A,**D,**C,*x,*old ;	//A D matrix
	double b[n];	//Right hand side of Ax=b
	double tolerance=.00001;

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
/*
			cout<<"\nA matrix "<<endl;
		 	for (i=0; i < n; i++)
				{
				cout<<"|";
					for(j=0;j<m;j++){

					  cout<<" "<<setw(8)<<A[i][j]<<" ";
					}
				cout<<"|"<<endl;
				}

*/
			//cout<<"entries in A matrix: "<<count<<endl;
	//		cout<<"\nRHS"<<endl;

			count =0;

		for(i=0;i<n;i++){

				fs>>nums;
				b[i]=nums;
				count++;
				}

/*			for (i=0; i < n; i++)
					{
					cout<<"|";
						cout<<" "<<setw(8)<<b[i]<<" ";
					cout<<"|"<<endl;
					}
*/
//	cout<<"entries in b vector: "<<count<<endl;

old = new double [n];

count=0;

diff=2;
while(diff>tolerance){
	count++;


	for(i=0;i<n;i++){

		old[i]=x[i];

			}

	for(int i=0; i<n; ++i)
			{
				sum = L = U = 0;
						//Sum lower half
						for(int j = 0; j < i; ++j)
								{
									L = L + (A[i][j] * x[j]);
								}
						//Sum upper half
						for( int j = (i+1); j < m; ++j)
								{
									U= U + (A[i][j] * x[j]);
								}

						sum = b[i] - L - U;

						x[i] = (1-omega)*x[i] + ( (omega/A[i][i]) * sum );
			}
	diff=tolCheck(x, old, n);



	/*if(ending<tolerance){
			cout<<ending<<endl;
			cout<<"ending condition"<<endl;
		}
		else cout<<"not yet"<<endl;
		*/



}

error= calcError(argc,argv,x,n);

outPutXSoltion(x,n);

choices(count,n,x,error);


}



