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
#include <ostream>


using namespace std;


void jacobi(int argc,char* argv[]){
	ifstream fs;
	//ifstream output;

	fs.open(argv[1]);
//	output.open(argv[2]);

	int i,j,k,l,m,n,count,choice;
	double nums,tolerance;
	double error;
	count=0;
	float sum,diff;
	fs.clear();
	fs>>n>>m;


	double **A,**D,**C,*x,*old ;	//A D matrix
	double b[n];	//Right hand side of Ax=b
	double ending=1.0;

	srand (time(NULL));


	//initial guess
		cout<<"\nInitial guess"<<endl;
		x=new double [n];
		for(i=0;i<n;i++){

			double v1 = (rand() %200 -100)/1.00;

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
tolerance=.00001;


diff=2;

while(diff>tolerance){
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
			//	cout<<"new X: "<<x[i]<<endl;

		}

	//printVector(x,n);


	diff=tolCheck(x, old, n); //differnce 2 norm of old and new x



	/*if(ending<tolerance){
			cout<<ending<<endl;
			cout<<"ending condition"<<endl;
		}
		else cout<<"not yet"<<endl;
		*/

}

ofstream output;
output.open("new.txt");

float temp2;

int resize = sqrt(n);


count =0;
for(i=0;i<resize;i++){
	cout<<"i "<<i<<endl;
		for(j=0;j<resize;j++){
			//k=j*n+i;


		output<<x[count]<<" ";
		count++;

		}
		output<<" \n";
		//cout<<i<<endl;
		cout<<count<<endl;
}
output.close();

//matVecMultV(A,x, n, m);

//cout<<"after loops"<<endl;
error= calcError(argc,argv,x,n);

choices(count,n,x,error);

delete []A;
delete []x;
}


