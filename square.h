#ifndef SQUARE_H
#define SQUARE_H


#include<stdio.h>
#include<math.h>
#define NUM_ARGS 3
#define INF -1

//assert
//isnan
//unit tests

int SolveSquare(double, double, double, double*, double*);
int SolveLinear(double, double, double*);
int Input(double*, double*, double*);
int Output(int, double, double);
int IsZero(double);

enum ERRORS {
    INPUT_ERROR  = 1,
    OUTPUT_ERROR = 2,

};

#endif
