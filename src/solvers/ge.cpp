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
#include "../headers/ge.h"
#include "../headers/operations.h"
#include <iomanip>


using namespace std;




void gaussianElim(int argc,char* argv[])
{

	ifstream fs;
	fs.open(argv[1]);

	int i,j,k,l,m,n,count;
	double nums,sum,tolerance,max;
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


			D=augMat(A,b,n,m);

				  l=m+1;

		    printMatrix(D,n,l);

		    old = new double [n];


			for(i=0;i<n;++i){
				max=0.0;

					//find row with largest largest value
						for(k=i;k<n;k++)
								{
								if(D[k][i]>max){
								max=D[k][i];
								rowSwap(D,i,k);
											//cout<<"swap"<<endl;
									}
							     }
					rowDiv(D,max,i,l);

					rowSubtraction(D,n,l,i);


					}

			x= new double[n];

							for(i=0;i<n;i++){
							 x[i]=0.0;
							 cout<<x[i]<<endl;
							}
 //this is x[2-1] = 1

					//time to backsolve
						 for(i=n-1; i>=0; i--)
						    {
							 sum=0;
						//	 cout<<i<<i+1<<n<<endl;
							// cout<<"B col "<<D[i][m]<<endl;
						        for(j=i+1; j<n; j++)
						        {	//cout<<"go"<<endl;
						            sum=sum+D[i][j]*x[j];
						         }
						        x[i]=D[i][m]-sum;
						    }

					cout<<"\nend "<<endl;
					printMatrix(D,n,l);

error= calcError(argc,argv,x,n);

choices(count,n,x,error);


}



