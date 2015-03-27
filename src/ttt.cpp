#include <iostream>

using namespace std;

int matrix[3][3];

int bar()
{
    // asigning values, I suppose this is done already.

    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            matrix[x][y]=1;
        }
    }

    // showing the matrix on the screen

    for(int x=0;x<3;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<3;y++)  // loop for the three elements on the line
        {
            cout<<matrix[x][y];  // display the current element out of the array
        }
    cout<<endl;  // when the inner loop is done, go to a new line
    }
    return 0;  // return 0 to the OS.
}


/*

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
#include <stdlib.h>     /* srand, rand
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>
#include "../operations/brackets.h"
#include "../operations/addMatrix.h"


using namespace std;

int main(int argc,char* argv[]) {


	// brackets(argc,argv);

	//double pointer pointer
	 double **A;
	 double **B;
	 double **X;
	//rows and columns of the matrix
	 int n,m,nums;
	 char matrix;
	 string test;

	 //stream variable
	 ifstream fs;

	 //is the file found?
	 if(argc != 2){
	 		cout<<"File not found"<<endl;
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



//	getline(fs,test);

	//cout<<test<<endl;

	//basic matrix test
		//rows=3;
		//cols=3;

	fs.clear();
	char c;

		fs>>c;
		cout<<"Matrix "<<c<<endl;


	fs>>n>>m;

	//cout<<"rows"<<rows<<endl;
	//cout<<"cols"<<cols<<endl;



//create matrix and assign   values
	A = new double *[n];
	for (int i=0; i < n; i++)
	{
		A[i]=new double [m];

		for(int j=0;j<m;j++){
			fs>>nums;

			A[i][j]=nums;

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



//Create the right hand side
	fs>>c;
	cout<<"Matrix "<<c<<endl;
	fs>>n>>m;

	B = new double *[n];
		for (int i=0; i < n; i++)
		{
			B[i]=new double [m];

			for(int j=0;j<m;j++){
				fs>>nums;

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

//X vector
		fs>>c;
		cout<<"Matrix "<<c<<endl;
		fs>>n>>m;

		X = new double *[n];
				for (int i=0; i < n; i++)
				{
					X[i]=new double [m];

					for(int j=0;j<m;j++){


						X[i][j]=1;

						//x[i][j]=rand()%100;

					}
				}

				for (int i=0; i < n; i++)
					{
					cout<<"|";
						for(int j=0;j<m;j++){

						  cout<<" "<<setw(2)<<X[i][j]<<" ";
						}
					cout<<"|"<<endl;
					}

//pass(A,B,X,n,m);


	return 0;
}


 */
