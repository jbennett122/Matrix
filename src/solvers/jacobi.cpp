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



using namespace std;


void jacobi(int argc,char* argv[]){
	ifstream fs;
	fs.open(argv[1]);

	int i,j,k,l,m,n,count,choice;
	float nums,sum;

	count=0;

	fs.clear();
	fs>>n>>m;


	double **A,**D,**C,*x,*old,*diff;	//A D matrix
	double b[n];	//Right hand side of Ax=b

/*
switch(choice){

case 1 :
	cout<<"jacobi"<<endl;

	jacobi(argc,argv);

	break;

case 2:
	cout<<"GS"<<endl;
		break;


}*/


srand (time(NULL));
//initial guess
for(i=0;i<n;i++){

	float v1 = rand() %200 -100;

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
cout<<"entries in A matrix: "<<count<<endl;

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

	cout<<"entries in b vector: "<<count<<endl;

	C = new double *[n];

for (i=0; i < n; i++)
{

		C[i]=new double [m];
			for(j=0;j<m;j++){

				 if(i==j){
					C[i][j]=0.0;

				 }else
				 {
					C[i][j]=A[i][j];

				 }

			}
}

//print C matrix
for (i=0; i < n; i++)
{
			cout<<"|";
				for(j=0;j<m;j++){

				  cout<<" "<<setw(8)<<C[i][j]<<" ";
				}
			cout<<"|"<<endl;
}



count=0;
do{




cout<<"\nold: "<<count<<endl;
	for(i=0;i<n;i++)
	{
					cout<<"|";
						cout<<" "<<setw(8)<<old[i]<<" ";
					cout<<"|"<<endl;
	}

cout<<endl;
//go row by row do matrix mult and matrix subtraction
	for (i=0; i < n; i++)
		{

			sum =0;
			for(j=0;j<m;j++){

				if(i!=j){
						//matrixMult(C, x, n,  m);

						//cout<<"Cx "<<A[i][j]<<" * " <<x[j]<<endl;

				sum = sum + (A[i][j] * x[j]);
						//cout<<"sum is: "<<sum<<endl;

						}

							}

						//new x vector
						x[i]=(b[i]-sum)/(A[i][i]);
						//cout<<sum<<endl;

		}

cout<<"old"<<endl;
	for(i=0;i<n;i++){
						cout<<"|";
							cout<<" "<<setw(8)<<old[i]<<" ";
						cout<<"|"<<endl;
		}
	cout<<"new"<<endl;
	for(i=0;i<n;i++){
						cout<<"|";
							cout<<" "<<setw(8)<<x[i]<<" ";
						cout<<"|"<<endl;
		}



	//tolCheck(x, old, n);

count++;
}while(count<2);


for(i=0;i<n;i++){
					cout<<"|";
						cout<<" "<<setw(8)<<x[i]<<" ";
					cout<<"|"<<endl;
	}

cout<<"endl"<<endl;
}


