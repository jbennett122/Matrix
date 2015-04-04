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


void jacobi(int argc,char* argv[]){
	ifstream fs;
	fs.open(argv[1]);

	int i,j,k,l,m,n,count,choice;
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

//	cout<<"entries in b vector: "<<count<<endl;

old = new double [n];

count=0;
do{
	count++;
	for(i=0;i<n;i++){

		old[i]=x[i];

			}

//go row by row do matrix mult and matrix subtraction
	for (i=0; i < n; i++)
		{
			sum =0;
			for(j=0;j<m;j++){

				 if(i!=j){

					 sum = sum + (A[i][j] * x[j]);
				 	 	 }
				//cout<<"sum is: "<<sum<<endl;
							}

						//new x vector
				x[i]=(b[i]-sum)/(A[i][i]);
				//cout<<x[i]<<endl;

		}

	tolerance=tolCheck(x, old, n);



	/*if(ending<tolerance){
			cout<<ending<<endl;
			cout<<"ending condition"<<endl;
		}
		else cout<<"not yet"<<endl;
		*/



}while(ending<tolerance);

error= calcError(argc,argv,x,n);

choices(count,n,x,error);


}


