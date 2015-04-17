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



	do{
		cin>>choice;

	switch(choice){

	case 1:

		cout<<"\nFinal X"<<endl;

			for(i=0;i<n;i++){
							cout<<"|";
								cout<<" "<<setw(8)<<x[i]<<" ";
							cout<<"|"<<endl;
						}

			cout<<"\nChoose Option\n1.X solution\n2.Iterations and error\n3.Exit to Main Menu"<<endl;

		break;

	case 2:

		cout<<"\nIterations: "<<count<<" and Percent error: "<<error<<endl;

		cout<<"\nChoose Option\n1.X solution\n2.Iterations and error\n3.Exit to Main Menu"<<endl;

		break;

	case 3:
	 cout<<"\nExiting to Solver Menu\n"<<endl;

	 	 break;

	default:
		cout<<"Choose a valid option"<<endl;

		}


	}while(choice!=3);
	cout<<"1. Jacobi\n2. Gauss Seidel\n3. SOR\n4. Gaussian Elimination\n5. L-U\n6. Bi-section\n7. Regula Falsi\n8. Newtons\n9. Exit"<<endl;


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

 	cout<<"M: ";
	cin>>m;

	inputFile<<n<<" "<<m<<"\n";

//cout<<"test1"<<endl;
	//create new A matrix

	Matrix= new double *[n];
	for(i=0;i<n;i++){
//cout<<"test2"<<endl;
		Matrix[i]=new double [m];

		for(j=0;j<m;j++){
	//		cout<<"test3"<<endl;
			Matrix[i][j]=0.0;

			}

		}


	for(i=0;i<n;i++){
//cout<<"test2"<<endl;


		for(j=0;j<m;j++){
	//		cout<<"test3"<<endl;
			Matrix[i][j]= (rand() %20-10)/3 ;

			}

		}
//cout<<"test4"<<endl;
	//make matrix diagonally dominate
	for(i=0;i<n;i++){
//cout<<"test5"<<endl;
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
//cout<<"test6"<<endl;

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
			 v1 = (rand() %20-10)/(rand() %5);
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

void rowSwap(double** A, const int& r1, const int& r2)
{
//	cout<<"swap"<<endl;

	double* temp = A[r1];
	A[r1] = A[r2];
	A[r2] = temp;


}

void printMatrix(double** A,int n, int m){
	int i,k,j;
cout<<"\n"<<endl;
	for (i=0; i < n; i++)
				{
				cout<<"|";
					for(j=0;j<m;j++){

				cout<<" "<<setw(8)<<A[i][j]<<" ";
								}
				cout<<"|"<<endl;
					}

}

double** augMat(double** A,double *b,int n,int m){

	int i,j,q;
	double **AM;

	q=m+1;
	AM= new double *[q];
//cout<<"t1"<<endl;
	for(i=0;i<n;i++){
	//cout<<"test2"<<endl;
			AM[i]=new double [q];



			for(j=0;j<q;j++){
			//	cout<<"A["<<i<<"]["<<j<<"]"<<endl;

				//cout<<"test3"<<endl;
				if(j==q-1){
			//	cout<<b[i]<<endl;
					AM[i][j]=b[i];

				}
				else{
			//	cout<<A[i][j]<<endl;
				AM[i][j]=A[i][j];
				}
				}

			}
//cout<<"t2"<<endl;
//printMatrix(AM,n,q);

return AM;

}

void rowSubtraction(double** A,int n, int m,int r){
	int j,i;
	for(i=r+1;i<n;i++){
//cout<<"i and r "<<i<<r<<endl;
//cout<<"next row "<<A[1][1]<<endl;
		if(A[i][i-1]!=0){
		for(j=0;j<m;j++){
			//cout<<"\nRow:"<<i+1<<endl;
			//cout<<A[i][j]<<" - " <<A[i][j]<<" * " <<A[r][j]<<endl;
			A[i][j]=A[i][j]- (A[i][j]*A[r][j]);
			//cout<<A[i][j]<<endl;
		}

		}
	//	else cout<<"not done"<<endl;
	}



}

void rowDiv(double **A,double max,int c,int m){
	int i=c;
	for(int j=c;j<m;j++){

		//cout<<A[i][j]<<" / "<<max<<endl;

		A[i][j]=A[i][j]/max;
	}



}



static void OUTPUT(int n, double **A, int ISW)
{
   int I, J, FLAG;

   cout<<"GENERAL LU FACTORIZATION"<<endl;
   if (ISW == 0)
      cout<<"The diagonal of L consists of all entries = 1.0"<<endl;
   else
      cout<<"The diagonal of U consists of all entries = 1.0"<<endl;
   cout<<"Entries of L below diagonal and entries of U above/on diagonal"<<endl;
   cout<<"- output by rows in overwrite format:"<<endl;
   for (I=1; I<=n; I++) {
      for (J=1; J<=n; J++) cout<<"  "<< A[I-1][J-1];
      cout<<endl;
   }
}

/* Absolute Value Function */
static double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
