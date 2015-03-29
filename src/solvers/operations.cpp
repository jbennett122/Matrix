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



using namespace std;


float *matrixMult(float *C,float *x,int n,int m){

	float sum=0;
	//multiply [n][0] to [n][m] by [n][0] sum all results

return x;





}



float tolCheck(float *x,float *old,int n){

	float *diff;
	float sum;
	float tolerance=0;
/*	cout<<"old"<<endl;

 for(int i=0;i<n;i++){
			cout<<old[i]<<endl;
	}
*/
	sum=0;



	diff= new float [n];
	for(int i=0;i<n;i++){

		diff[i]=old[i]-x[i];

		sum=sum + diff[i];

	}
	cout<<abs(sum)<<endl;
	tolerance = sqrt (abs(sum));

//return diff;

	cout<<"tolerance: "<<setprecision(9)<<tolerance<<endl;

	return tolerance;

}
