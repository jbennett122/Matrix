/*
 * newtons.cpp
 *
 *  Created on: Apr 21, 2015
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
#include "../headers/newtons.h"
#include <iomanip>


using namespace std;

float fX(float x ){
	float fx;
	//fx = pow(x,3) - x - 2;


	fx=  pow(x,4)- 2*(pow(x,3))- 9*(pow(x,2))+ 8;


	//fx=pow(x,3)- 7*pow(x,2)+ 8*x -3;

return (fx);
}

float fPX(float x){
	float dfdx;

//	dfdx = 3*(pow(x,2)) - 1;

	//X4 + 2x3 -9x2 -2x +8 = 0
	//4x3 + 6x2 -18x  - 2
	dfdx=4*(pow(x,3))+ 6*(pow(x,2))- 18*x -2;

   // dfdx = 3* pow(x,2) -14*x +8 ;

	return (dfdx);
}

void newtons(){
	 float a,newA;
	    double *x;
	    int count = 0;
	    int iter,i,n,choice;
	    float tolerance=1.e-5;
	    ofstream output;
	       	string fileName;


	       	//name of output file
	       	output.open("question8.txt");


  cout << "Enter initial starting point: ";
  cin >> a;

  newA=0.0;

  while(abs(a-newA) > tolerance){


    a = newA;

     newA = a - fX(a)/fPX(a);

     output<<"\nx: "<<newA<<

count++;
  }

  cout<<"\nChoose Option\n1.X solution\n2.Iterations \n3.Exit to Main Menu"<<endl;

  	choice=99999;
output.close();

	do{
		cin>>choice;

	switch(choice){

	case 1:
		cout<<"X: "<<newA<<endl;
			cout<<"\nChoose Option\n1.X solution\n2.Iterations\n3.Exit to Main Menu"<<endl;

		break;

	case 2:

		cout<<"\nIterations: "<<count<<endl;

		cout<<"\nChoose Option\n1.X solution\n2.Iterations\n3.Exit to Main Menu"<<endl;

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



