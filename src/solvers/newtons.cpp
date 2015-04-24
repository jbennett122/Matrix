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

float fN(float x ){
	float fOx;

	fOx = 4*x - cos(x);

return fOx;
}

float fPN(float x){

	float dfdx;

	dfdx = 4 + sin(x);

	return dfdx;
}

void newtons(){
  double r,rnew;

  double tolerance;
  int i,n;

  cout << "Enter initial starting point: ";
  cin >> rnew;
  cout<<"Max number of iterations: "<<endl;
  cin>>n;

  tolerance=1.0/10000.0;

  for(i = 0; i < n; i = i + 1){
    r = rnew;

    rnew = r - fN(r)/fPN(r);

    cout<<rnew<<endl;
    // check for convergence and quit if done
    if(abs(r-rnew) < tolerance){
      cout << "Root is " << rnew << " within "<< tolerance << "\n";

      exit(0);
    }
  }

  cout << "Failed to converge after " << n << " iterations.\n";
  exit(1);
}
