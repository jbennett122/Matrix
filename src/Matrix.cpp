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
#include "headers/jacobi.h"
#include "headers/operations.h"


using namespace std;

int main(int argc,char* argv[]) {

 	 int n,m,choice;

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
		randomMatrix();
cout<<"chose solver"<<endl;
cout<<"1. Jacobi\n2. Gauss Seidel\n3. SOR\n4. Gaussian Elimination\n5. L-U\n6. Bi-section\n7. Regula Falsi\n8. Newtons"<<endl;
cin>>choice;
switch(choice){

case 1 :
	cout<<"jacobi"<<endl;

	jacobi(argc,argv);

	break;

case 2:
	cout<<"GS"<<endl;
		break;


}


	return 0;
}
