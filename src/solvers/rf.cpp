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
   // fx1 = pow(x-4,2) -8;  //test
   // fx1 = pow(x,3) - x - 2;
   fx1=x + log(x);

    return (fx1);
}

void rf()
{
    float a,b,mid;
    double *x;
    int count = 0;
    int iter,n,choice;
    float tolerance=1.e-5;

	ofstream output2;
   	string fileName;


   	//name of output file
   	output2.open("question7.txt");




    cout <<"Enter L = ";
    cin >> a;
    cout <<"Enter R = ";
    cin >> b;


    while((abs(fx(mid)) > tolerance))
       {
      // mid = b - (   fx(b) * ((b - a) / fx(b) - fx(a)));
    	//mid = a + (b-a)*(- fx(a)) / (fx(b) - fx(a));

//mid = b - (fx(b)*(b-a)/fx(b)-fx(a));


		mid = ((a * fx(b)) - (b*fx(a)))/(fx(b) -fx(a));


       // cout <<"a=" <<a<<" | b="<<b<<" | mid=" <<mid<<" | " << "  f(a)=" << fx(a) << " |  f(b)=" << fx(b) << " |  f(mid)=" << fx(mid) << endl << endl;

        if(  fx(mid)*fx(a)  < 0 )
        {
           b=mid;
           cout<<"new b "<<b<<endl;
        }
        else
        	{
        	a=mid;
        	cout<<"new a "<<a<<endl;
        	}

              cout<<"X is : "<<mid<<endl;
              output2<<"\nx: "<<mid<<" F(x): "<<fx(mid);

        count++;
    }



    cout<<"\nChoose Option\n1.X solution\n2.Iterations \n3.Exit to Main Menu"<<endl;

    	choice=99999;

output2.close();
	do{
		cin>>choice;

	switch(choice){

	case 1:

		cout<<"\nFinal X: "<<mid<<endl;



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
