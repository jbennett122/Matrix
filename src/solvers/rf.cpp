/*
 * rf.cpp
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
#include "../headers/rf.h"
#include <iomanip>


using namespace std;


float fx (float x)
{
    float fx1;
    fx1 = pow(x,3) + pow(x,2) - (3*x) - 3; // equation place holder
    return (fx1);
}

void rf()
{
    float x1,x2,x3;
    double *x;
    int count = 0;
    int iter,n,choice;

    cout <<"Enter x1 = ";
    cin >> x1;
    cout <<"Enter x2 = ";
    cin >> x2;
    cout <<"Enter number of iterations = ";
    cin >> iter;

//  int fx1 = (x1^3) + (x1^2) - (3x1) - 3;
//  int fx2 = (x2^3) + (x2^2) - (3x2) - 3;
    do
    {
        if(count == iter)
        {
            break;
        }

        x3 = x1 - (fx(x1)*((x1 - x2) / fx(x1) - fx(x2)));

      //  cout <<"x1=" << x1 <<" | x2="<< x2 <<" | x3=" << x3 <<" | " << "  f(x1)=" << fx(x1) << " |  f(x2)=" << fx(x2) << " |  f(x3)=" << fx(x3) << endl << endl;

        if( fx(x1) * fx(x3) < 0 )
        {
            x2 = x3;
        }
        else
        {
            x1 = x3;
        }
        count++;
    }
    while ( abs(x1 - x2) < 0.0000001 || fx(x3) == 0 );


    cout<<"\nChoose Option\n1.X solution\n2.Iterations \n3.Exit to Main Menu"<<endl;

    	choice=99999;


	do{
		cin>>choice;

	switch(choice){

	case 1:

		cout<<"\nFinal X"<<endl;


	    cout <<"x1=" << x1 <<" | x2="<< x2 <<" | x3=" << x3 <<" | " << "  f(x1)=" << fx(x1) << " |  f(x2)=" << fx(x2) << " |  f(x3)=" << fx(x3) << endl << endl;


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
