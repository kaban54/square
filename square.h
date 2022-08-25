#ifndef SQUARE_H
#define SQUARE_H


//#define NDEBUG


#include<assert.h>
#include<stdio.h>
#include<math.h>


#define MAX_LEN 100

//assert
//isnan
//unit tests



int Input  (char *name, double *a, double *b, double *c);
int Output (char *name, int num_root, double x1, double x2);

int SolveSquare (double a, double b, double c, double *x1, double *x2);
int SolveLinear (double a, double b, double *x);

int IsZero (double x);
int Eq     (double x, double y);

void SquareTest (FILE *in, FILE *out);

int Correct        (int    in_nr, double inx1, double inx2,
                    int num_root, double   x1, double   x2);

void PrintFail     (FILE *out, double a, double b, double c,
                    int    in_nr, double inx1, double inx2,
                    int num_root, double   x1, double   x2);

void PrintSuccess  (FILE *out, double a, double b , double c,
                    int num_root, double x1, double x2);

void PrintInpError (FILE *out, char *buf);


enum ERRORS {
    INPUT_ERROR  = 1,
    OUTPUT_ERROR = 2,

};

enum ROOT_CNT {
    INF  = -1,
    ZERO =  0,
    ONE  =  1,
    TWO  =  2,
};

#endif


