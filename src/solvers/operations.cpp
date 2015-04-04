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
#include "../headers/operations.h"



using namespace std;

void choices(int count,int n, double *x,double error){

	int choice,i;
	cout<<"\nChoose Option\n1.X solution\n2.Iterations and error\n3.Exit to Main Menu"<<endl;

	choice=99999;

	cin>>choice;

	do{
	switch(choice){

	case 1:

		cout<<"\nFinal X"<<endl;

			for(i=0;i<n;i++){
							cout<<"|";
								cout<<" "<<setw(8)<<x[i]<<" ";
							cout<<"|"<<endl;
						}
		break;

	case 2:

		cout<<"\nIterations: "<<count<<" and Percent error: "<<error<<endl;
		break;

	case 3:
	 cout<<"\nExiting to Solver Menu\n"<<endl;
	 	 break;

	default:
		cout<<"Choose a valid option"<<endl;

		}
	cin>>choice;

	}while(choice!=3);

}
void matVecMultV(double **A,double *x,int n,int m){

	ofstream rightHand;


	double sum=0;
	double *b;

	b=new double [n];
	for(int i=0;i<n;i++){
	  sum=0.0;
		for(int j=0;j<m;j++){
			sum += A[i][j] * x[j];
			//cout<<A[i][j]<<" * "<<x[j]<<endl;
		//	cout<<"A["<<i<<"]"<<"["<<j<<"]"<<" * x["<<j<<"] :"<< sum<<endl;
			b[i]=sum;}

	}

//cout<<"Finding right side"<<endl;

	rightHand.open("input9.txt",fstream::app);

	rightHand<<"\n";
	for(int i=0;i<n;i++){

		//cout<<xnew[i]<<endl;
		rightHand<<b[i]<<" ";

	}

rightHand.close();

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

	int i,j;
	double v1,sum;
	double **Matrix,*x;

	int n,m;
	srand (time(NULL));
	string k;
	inputFile.open("input9.txt");

	cout<<"enter dimensions:"<<endl;
	cout<<"N: ";
	cin>>n;

	inputFile<<n;
	inputFile<<" ";
	cout<<"M: ";
	cin>>m;

	inputFile<<m;
	inputFile<<"\n";


	//create new A matrix
	Matrix= new double *[n];
	for(i=0;i<n;i++){

		Matrix[i]=new double [m];

		for(j=0;j<m;j++){

			Matrix[i][j]= (rand() %200-100) /((rand() %3)) ;

			}

		}

	//make matrix diagonally dominate
	for(i=0;i<n;i++){

		sum=0.0;
		for(j=0;j<m;j++){
			sum+= abs(Matrix[i][j]);
			}
		Matrix[i][i]=sum;

		}

	//write DD A matrix to file
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			inputFile<<Matrix[i][j]<<" ";
			}
		}


	//RHS -- since moved to multMatVec function
	/*inputFile<<"\n";
	for(i=0;i<n;i++){

		 v1 = rand() %200-100 ;
		inputFile<<v1<<" ";


	}
	*/
	inputFile.close();


	//create random X vector solution
	solutionFile.open("solution9.txt");
x= new double [n];
	for(i=0;i<n;i++){
			 v1 = (rand() %200-100)/((rand() %7));
			 x[i]=v1;
			solutionFile<<v1<<" ";

			}

	solutionFile.close();

//calculate Ax and append B to input9.txt file
	matVecMultV( Matrix,x, n, m);


	delete []Matrix;
	delete []x;

}

double calcError(int argc,char* argv[],double *x,int n){


	ifstream solution;
	double top,bottom;
	double *xActual,*xDiff;
	int i;
	float perctError;
	solution.open("solution9.txt");
	top=bottom=0.0;
	xActual=new double[n];
	perctError=0.0;
for(i=0;i<n;i++){


solution>>xActual[i];


}

xDiff=matrixSubtraction(xActual,x,n);


top=matrixSum(xDiff,n);
bottom=matrixSum(xActual,n);

//cout<<"top: "<<top<<" bottom: "<<bottom<<endl;

perctError=(sqrt(top)/sqrt(bottom));


//cout<<"error: "<<perctError<<endl;


	return perctError;

}

double *matrixSubtraction(double *xA, double *x,int n){

	double *xDiff;

	xDiff= new double [n];
	for(int i=0;i<n;i++){

		xDiff[i]=xA[i]-x[i];

	}

	for(int i=0;i<n;i++){


			xDiff[i]=xA[i]-x[i];
		//	cout<<xA[i]<<"-"<<x[i]<<" = "<<xDiff[i]<<endl;
		}


	return xDiff;

}

double matrixSum(double *Matrix,int n){
	double sum=0.0;
	for(int i=0;i<n;i++){

		sum =pow(Matrix[i],2);

	}

	sum =  sqrt(sum);
	return sum;



}


