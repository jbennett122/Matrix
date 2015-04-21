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

void newtons(){


	double r,i,j,k,l,n,m,xi,xi1;
	const double e=.000001;
	xi=1.0;
	xi1=0.0;


	cout<<"enter radicand:"<<endl;

	cin>>r;
	cout<<"Enter index: "<<endl;
	cin>>i;

	m=i-1;

	while (abs(xi1-xi)>=e){

		xi1=xi;
		xi= xi + ((-1*pow(xi,i))+r)/(i*(pow(xi,m)));
	}


}
