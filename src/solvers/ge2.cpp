/*
 * ge2.cpp
 *
 *  Created on: Apr 25, 2015
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


void ge2(int argc,char* argv[]){

		ifstream fs;
		fs.open(argv[1]);

		int i,j,k,l,m,n,count;
		double nums, tolerance,max;
		double error;
		count=0;

		fs.clear();
		fs>>n>>m;

		float sum,diff;

		double **A,**D,**C,*x,*old;	//A D matrix
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

				count =0;

			for(i=0;i<n;i++){

					fs>>nums;
					b[i]=nums;
					count++;
					}

			gaussian(A, b, x,n);

			outPutXSoltion(x,n);

			error= calcError(argc,argv,x,n);

			choices(count,n,x,error);


}
