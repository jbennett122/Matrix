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




using namespace std;

void bisection()
{
    float x1,x2,x3;
    int count = 0;
    int iter,n,m;
    double error;
    double **A,**D,**C,*x,*old,*diff;

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

        x3 = (x1 + x2)/2;

        cout <<"x1=" << x1 <<" | x2="<< x2 <<" | x3=" << x3 <<" | " << "  f(x1)=" << f(x1) << " |  f(x2)=" << f(x2) << " |  f(x3)=" << f(x3) << endl << endl;

        //float temp1 = f(x1);
        //float temp2 = f(x3);
        if( f(x1) * f(x3) < 0 )
        {
            x2 = x3;
        }
        else
        {
            x1 = x3;
        }
        count++;
    }
    while ( abs(x1 - x2) < 0.0000001 || f(x3) == 0 );


    choices(count,n,x,error);


}

float f (float x)
{
    float fx1;
    //fx1 = pow(x,3) + pow(x,2) - (3*x) - 3;

    fx1 = x + log(x); //pow(x,2)  - 1;
    return (fx1);
}
