/*
 * operations.h
 *
 *  Created on: Mar 28, 2015
 *      Author: Justin
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

void choices(int count,int n, double *x,double error);

double matVecMultD(double **A,double *x,int n,int m);

void matVecMultV(double **A,double *x,int n,int m);

double tolCheck(double *x,double *old,int n);

void randomMatrix();

double calcError(int argc,char* argv[],double *x,int n);

double *matrixSubtraction(double *xA, double *x,int n);

double matrixSum(double *Matrix,int n);

#endif /* OPERATIONS_H_ */
