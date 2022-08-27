#ifndef SQUARE_H
#define SQUARE_H

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

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Gets equation coefficients from the input file
//!
//! @param   name       input file name
//! @param   pcoefs     pointer to coefficients structure
//!
//! @return  0 if the input is correct, 1 if an input error occurs
//}----------------------------------------------------------------------------------------------------------------

int Input  (char *name, struct coefficients *pcoefs);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Prints solution to the output file
//!
//! @param   name       output file name
//! @param   sol        solution
//!
//! @return  0 if no errors occurred, 2 if an output error occurs
//}----------------------------------------------------------------------------------------------------------------

int Output (char *name, struct solution sol);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Solves quadratic equation
//!
//! @param   coefs      coefficients of quadratic equation
//! @param   psol       pointer to solution structure
//!
//! @return  num_root   number of roots
//}----------------------------------------------------------------------------------------------------------------

int SolveSquare(struct coefficients coefs, struct solution *psol);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Solves linear equation
//!
//! @param   a      a coefficient
//! @param   b      b coefficient
//! @param   x      pointer to the root of the equation
//!
//! @return  num_root   number of roots
//}----------------------------------------------------------------------------------------------------------------

int SolveLinear (double a, double b, double *x);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   compares double number with zero
//!
//! @param   x  number to compare
//!
//! @return  1 if number equals zero, 0 if not
//}----------------------------------------------------------------------------------------------------------------

int IsZero (double x);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   compares two double numbers
//!
//! @param   x  number to compare
//! @param   y  number to compare
//!
//! @return  1 if numbers are equal, 0 if not
//}----------------------------------------------------------------------------------------------------------------

int Eq     (double x, double y);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Tests SolveSquare function
//!
//! @param   in      input file
//! @param   out    output file
//}----------------------------------------------------------------------------------------------------------------

void SquareTest (FILE *in, FILE *out);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Checks if solution is correct
//!
//! @param   inp_sol    correct solution
//! @param       sol    solution to check
//!
//! @return  1 if solution is correct, 0 if not
//}----------------------------------------------------------------------------------------------------------------

int Correct        (struct solution inp_sol,
                    struct solution     sol);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Prints test fail message
//!
//! @param   out        output file
//! @param   coefs      coefficients of quadratic equation
//! @param   inp_sol    correct solution
//! @param   sol        incorrect solution
//}----------------------------------------------------------------------------------------------------------------

void PrintFail     (FILE *out,
                    struct coefficients coefs,
                    struct solution inp_sol,
                    struct solution     sol);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Prints test success message
//!
//! @param   out        output file
//! @param   coefs      coefficients of quadratic equation
//! @param   sol        solution
//}----------------------------------------------------------------------------------------------------------------

void PrintSuccess  (FILE *out,
                    struct coefficients coefs,
                    struct solution     sol);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Prints test input error message
//!
//! @param   out    output file
//! @param   buf    string with input error
//}----------------------------------------------------------------------------------------------------------------

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


