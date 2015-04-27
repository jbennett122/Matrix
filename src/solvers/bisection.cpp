/*
 * bisection.cpp
 *
 *  Created on: Apr 20, 2015
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
#include "../headers/bisection.h"
#include <iomanip>


float f (float x)
{
    float fx;
   //fx1 = pow(x,3) - x - 2; //pow(x,3) + pow(x,2) - (3*x) - 3;

    fx = x + log(x); //pow(x,2)  - 1;
    return (fx);
}

using namespace std;

void bisection()
{
    float a,b,mid;
    int count = 0;
    int iter,n,m,choice;
    double error;

    ofstream output;
    	string fileName;


    	//name of output file
    	output.open("question6.txt");



    float tolerance=.00001;

    cout <<"Enter L = ";
    cin >> a;
    cout <<"Enter R = ";
    cin >> b;

    mid= 10;

int max =15;
//  int fx1 = (x1^3) + (x1^2) - (3x1) - 3;
//  int fx2 = (x2^3) + (x2^2) - (3x2) - 3;
    while((abs(f(mid)) > tolerance))
    {
    	/*if( (abs(f(mid)) <tolerance)){
    		cout<<"found mid"<<endl;

    		cout<<"is "<<f(mid)<<" < "<<tolerance<<" ?"<<endl;

    		break;
    	}*/

        mid = (a + b)/2;

       // cout <<"a=" <<a<<" | b="<<b<<" | mid=" <<mid<<" | " << "  f(a)=" << f(a) << " |  f(b)=" << f(b) << " |  f(mid)=" << f(mid) << endl << endl;

        if( f(mid) < 0 )
        {
        	//cout<<f(mid)<<" f(mid) less that 0"<<endl;
           a = mid;
         //  cout<<"new a "<<a<<endl;
        }
        else
        {	//cout<<f(mid)<<" f(mid) greater than 0"<<endl;
            b= mid;
          //  cout<<"new b "<<b<<endl;
        }
        count++;
        cout<<"X is : "<<mid<<endl;
        output<<"\nx: "<<mid<<" F(x): "<<f(mid);
    }



    cout<<"\nChoose Option\n1.X solution\n2.Iterations \n3.Exit to Main Menu"<<endl;

    	choice=99999;
output.close();

	do{
		cin>>choice;

	switch(choice){

	case 1:

		cout<<"\nx: "<<mid<<" F(x): "<<f(mid)<<endl;


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


