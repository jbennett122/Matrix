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


		/*		rowSwap( A,  r1, r2);

				cout<<"\nA matrix row swap "<<endl;
							 	for (i=0; i < n; i++)
									{
									cout<<"|";
										for(j=0;j<m;j++){

										  cout<<" "<<setw(8)<<A[i][j]<<" ";
										}
									cout<<"|"<<endl;
									}
		*/

				D=augMat(A,b,n,m);

				  l=m+1;
 printMatrix(D,n,l);
				old = new double [n];

				count=2;
x= new double[n];
				for(i=0;i<n;i++){

				 x[i]=0.0;
cout<<x[i]<<endl;
					}

			//	cout<<"test1"<<endl;
do{



//A[3][0]=888;

						for(i=0;i<n;++i){
							max=0.0;

								//max=D[i][i];
								cout<<"max is "<<max<<endl;
							cout<<"Dii is  "<<D[1][1]<<endl;
							 cout<<"i is "<<i<<endl;
							//find row with largest largest value
									for(k=i;k<n;k++)
										{
										if(D[k][i]>max){
											max=D[k][i];
											rowSwap(D,i,k);
											//cout<<"swap"<<endl;
											}

								//		cout<<"Aij is  "<<A[i][j]<<endl;
									//	cout<<"max after row "<<k<<" is "<<max<<endl;
								        }
							//		cout<<"Aii / max is  "<<A[i][i]<<" / "<<max<<endl;

									rowDiv(D,max,i,l);
									cout<<"row div done"<<endl;
									printMatrix(D,n,l);


									cout<<"sub"<<endl;
									rowSubtraction(D,n,l,i);
									printMatrix(D,n,l);

						}



					//tolerance=tolCheck(x, old, n);



					/*if(ending<tolerance){
						cout<<ending<<endl;
						cout<<"ending condition"<<endl;
					}
					else cout<<"not yet"<<endl;
					*/
					cout<<n<<endl;
					cout<<count++<<endl;

				}while(count<n);

x[n-1]=D[n-1][l-1];

					//time to backsolve
						 for(i=n-1; i>=0; i--)
						    {
						        sum=0;
						        for(j=i+1; j<=n; j++)
						        {
						            sum=sum+D[i][j]*x[j];
						        }
						        x[i]=(D[i][n+1]-sum);
						    }


					cout<<"\nend "<<endl;
					printMatrix(D,n,l);



error= calcError(argc,argv,x,n);

choices(count,n,x,error);


}



