#include "square.h"



void SquareTest(FILE *in, FILE *out)
{
    char buf[MAX_LEN] {};

    struct coefficients coefs {};
    struct solution     sol   {};
    struct solution inp_sol   {};

    while(1)
    {
        if (fgets(buf, MAX_LEN, in) == NULL) break;

        if (TEST_NUM_ARGS != sscanf(buf, "%lf %lf %lf %d %lf %lf",
                                    &coefs.a, &coefs.b, &coefs.c,
                                    &inp_sol.num_root, &inp_sol.x1, &inp_sol.x2))
        {
            PrintInpError(out, buf);
            continue;
        }

        sol.num_root = SolveSquare(coefs, &sol);

        if (!Correct  (inp_sol, sol))
            PrintFail (out, coefs, inp_sol, sol);
        else
            PrintSuccess (out, coefs, sol);

    }
}


int Correct(struct solution inp_sol, struct solution sol)
{
    int in_nr    = inp_sol.num_root,
        num_root =     sol.num_root;

    double x1   =     sol.x1,
           x2   =     sol.x2,
           inx1 = inp_sol.x1,
           inx2 = inp_sol.x2;



    if (in_nr != num_root) return 0;

    switch(num_root)
    {
    case INF:
        return 1;

    case ZERO:
        return 1;

    case ONE:
        if (Eq(x1, inx1)) return 1;
        else              return 0;

    case TWO:
        if ((Eq(x1, inx1) && Eq(x2, inx2)) || (Eq(x1, inx2) && Eq(x2, inx1)))
            return 1;
        else
            return 0;

    default:
        return 0;
    }
}


void PrintFail(FILE *out,
               struct coefficients coefs,
               struct solution inp_sol,
               struct solution     sol)
{
    fprintf (out,
             "a = %.2lf b = %.2lf c = %.2lf num_root = %d x1 = %.2lf x2 = %.2lf "
             " Test failed.\n"
             "Function returned num_root = %d, x1 = %.2lf, x2 = %.2lf",
             coefs.a, coefs.b, coefs.c,
             inp_sol.num_root, inp_sol.x1, inp_sol.x2,
                 sol.num_root,     sol.x1,     sol.x2);
}


void PrintSuccess(FILE *out,
                  struct coefficients coefs,
                  struct solution sol)
{
    fprintf (out,
             "a = %.2lf b = %.2lf c = %.2lf num_root = %d x1 = %.2lf x2 = %.2lf "
             " Test passed successfully.\n",
             coefs.a, coefs.b, coefs.c,
             sol.num_root, sol.x1, sol.x2);
}


void PrintInpError(FILE *out, char *buf)
{
    int i = 0;

    while (buf[i] != '\n' && buf[i] != '\0') i++;

    if (buf[i] == '\n') buf[i] = '\0';

    fprintf(out, "%s Input Error.\n", buf);
}



