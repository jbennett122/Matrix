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
#include <stdlib.h>




using namespace std;


double *matVecMult(double **A,double *x,int n,int m){

	double sum=0;
	//multiply [n][0] to [n][m] by [n][0] sum all results

	double *xnew,entry;

	xnew=new double [n];
	for(int i=0;i<n;i++){
	  sum=0.0;
		for(int j=0;j<m;j++){
			sum += A[i][j] * x[j];
			}
		xnew[i]=sum;
	}


cout<<"matvecmatrix"<<endl;

	for(int i=0;i<n;i++){

		cout<<xnew[i]<<endl;
	}


	return xnew;

}


double tolCheck(double *x,double *old,int n){

	double *diff;
	double sum;
	double tolerance=0;
/*	cout<<"old"<<endl;

 for(int i=0;i<n;i++){
			cout<<old[i]<<endl;
	}
*/
	sum=0;

	diff= new double [n];
	for(int i=0;i<n;i++){

		diff[i]=old[i]-x[i];

		sum=sum + diff[i];

	}

	tolerance = sqrt (pow(sum,2));

	cout<<"tolerance: "<<setprecision(4)<<tolerance<<endl;

	return tolerance;

}



void randomMatrix(){


	ofstream inputFile;
	ofstream solutionFile;

	int i;
	double v1;

	int n,m;
	srand (time(NULL));
	string k;
	inputFile.open("input9.txt");

	cout<<"enter dimnesions:"<<endl;
	cout<<"N: ";
	cin>>n;

	inputFile<<n;
	inputFile<<" ";
	cout<<"M: ";
	cin>>m;

	inputFile<<m;
	inputFile<<"\n";

	int mult =  n*m;

	for(i=0;i<mult;i++){
		 v1 = rand() %200-100 ;

		inputFile<<v1<<" ";

		}

	inputFile.close();
	solutionFile.open("solution9.txt");

	for(i=0;i<n;i++){
			 v1 = rand() %200-100 ;

			solutionFile<<v1<<" ";

			}

	solutionFile.close();
}



