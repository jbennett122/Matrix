//============================================================================
// Name        : Matrix.cpp
// Author      : Justin Bennett
// Version     :
// Copyright   : Your copyright notice...you notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>     /* srand, rand */
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>



using namespace std;

int main(int argc,char* argv[]) {


	// brackets(argc,argv);

	//double pointer pointer
	 double **A;
	 double **B;
	 double **X;
	//rows and columns of the matrix
	 double nums;
	 int n,m;

	 char matrix;
	 string test;

	 //stream variable
	 ifstream fs;
	 ifstream fs2;
	 //is the file found?
	 if(argc != 3){
	 		cout<<"Files not found"<<endl;
	 		return -1;
	 	}

	//file already open?
	// cerr<<fs.is_open()<<endl;

	//take argument and open file
	 fs.open(argv[1]);

	//should be open now
	// cerr<<fs.is_open()<<endl;

	   if (!fs.is_open())
	   {
	     cout << "Operation not successfully performed\n";
	     fs.close();
	   }

	for(int i=0;i<argc;i++)
		 		printf("Argument %d: %s\n", (i), argv[i]);


		fs2.open(argv[2]);




//	getline(fs,test);

	//cout<<test<<endl;

	//basic matrix test
		//rows=3;
		//cols=3;

	fs.clear();
/*	char c;

		fs>>c;
		cout<<"Matrix "<<c<<endl;

*/
	fs>>n>>m;

	//cout<<"rows"<<rows<<endl;
	//cout<<"cols"<<cols<<endl;

int count=0;

//create matrix and assign   values
	A = new double *[n];
	for (int i=0; i < n; i++)
	{
		A[i]=new double [m];

		for(int j=0;j<m;j++){
			fs>>nums;

			A[i][j]=nums;
			count++;
			//x[i][j]=rand()%100;

		}
	}

	for (int i=0; i < n; i++)
		{
		cout<<"|";
			for(int j=0;j<m;j++){

			  cout<<" "<<setw(2)<<A[i][j]<<" ";
			}
		cout<<"|"<<endl;
		}

	cout<<count<<endl;

	fs>>n;
/*
		B = new double *[n];
			for (int i=0; i < n; i++)
			{
				B[i]=new double [m];

				for(int j=0;j<m;j++){
					fs2>>nums;

					B[i][j]=nums;

					//x[i][j]=rand()%100;

				}
			}

			for (int i=0; i < n; i++)
				{
				cout<<"|";
					for(int j=0;j<m;j++){

					  cout<<" "<<setw(2)<<B[i][j]<<" ";
					}
				cout<<"|"<<endl;
				}

*/
//pass(A,B,X,n,m);


	return 0;
}
