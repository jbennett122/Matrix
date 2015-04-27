/*
 * operations.h
 *
 *  Created on: Mar 28, 2015
 *      Author: Justin
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

void choices(int count,int n, double *x,double error);

void choices2(int count,double *x,int n);

double matVecMultD(double **A,double *x,int n,int m);

void outPutXSoltion(double * x,int n);

void matVecMultV(double **A,double *x,int n,int m);

double tolCheck(double *x,double *old,int n);

void randomMatrix();

double calcError(int argc,char* argv[],double *x,int n);

double *matrixSubtraction(double *xA, double *x,int n);

double matrixSum(double *Matrix,int n);

void rowSwap(double** A, const int& r1, const int& r2);

void printMatrix(double** A,int n, int m);

void printVector(double* x,int n);

void rowSubtraction(double** A,int n, int m,int r);

void rowDiv(double **A,double max,int c,int m);

double dot(double* b, double* x, int n);

double** augMat(double** A,double *b,int n,int m);

double **ATrans(double** A, int n,  int m);

double absval(double);

void OUTPUT(int n, double **A, int);

double pivot(double **A ,double *b,int n, int i);

void triangle(double **A ,double *b,int n);

double dotProduct(double *u, double *v, int k1,int k2);

void backSubstit(double **A, double *b, double *x,int n);

void gaussian(double **A, double *b, double *x,int n);

#endif /* OPERATIONS_H_ */
