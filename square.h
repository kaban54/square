#ifndef SQUARE_H
#define SQUARE_H

//
//  #define NDEBUG


#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100
#define NUM_ARGS 3
#define TEST_NUM_ARGS 6

struct coefficients
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

struct solution
{
    int num_root = 0;
    double x1 = NAN;
    double x2 = NAN;
};


int Input  (char *name, struct coefficients *pcoefs);
int Output (char *name, struct solution sol);

int SolveSquare(struct coefficients coefs, struct solution *psol);
int SolveLinear (double a, double b, double *x);

int IsZero (double x);
int Eq     (double x, double y);

void SquareTest (FILE *in, FILE *out);

int Correct        (struct solution inp_sol,
                    struct solution     sol);

void PrintFail     (FILE *out,
                    struct coefficients coefs,
                    struct solution inp_sol,
                    struct solution     sol);

void PrintSuccess  (FILE *out,
                    struct coefficients coefs,
                    struct solution     sol);

void PrintInpError (FILE *out, char *buf);


enum ERRORS {
    INPUT_ERROR  = 1,
    OUTPUT_ERROR = 2,
    ARG_ERROR    = 3,

};

enum ROOT_CNT {
    INF  = -1,
    ZERO =  0,
    ONE  =  1,
    TWO  =  2,
};

#endif


