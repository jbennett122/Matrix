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

void rowSwap(double** A, const int& r1, const int& r2);

void printMatrix(double** A,int n, int m);

void rowSubtraction(double** A,int n, int m,int r);

void rowDiv(double **A,double max,int c,int m);

double dot(double* b, double* x, int n);

double** augMat(double** A,double *b,int n,int m);

double **ATrans(double** A, int n,  int m);

static double absval(double);

static void OUTPUT(int n, double **A, int);

#endif /* OPERATIONS_H_ */
