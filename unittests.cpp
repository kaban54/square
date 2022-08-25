#include "square.h"


void SquareTest(FILE *in, FILE *out)
{
    char buf[MAX_LEN];

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN, inx1 = NAN, inx2 = NAN;
    int num_root = 0, in_nr = 0;

    while(1)
    {
        if (fgets(buf, MAX_LEN, in) == NULL) break;

        if (6 != sscanf(buf, "%lf%lf%lf%d%lf%lf", &a, &b, &c, &in_nr, &inx1, &inx2))
        {
            PrintInpError(out, buf);
            continue;
        }

        num_root = SolveSquare(a, b, c, &x1, &x2);

        if (!Correct(in_nr, inx1, inx2, num_root, x1, x2))
            PrintFail(out, a, b, c, in_nr, inx1, inx2, num_root, x1, x2);
        else
            PrintSuccess(out, a, b, c, num_root, x1, x2);

    }
}


int Correct(int in_nr, double inx1, double inx2, int num_root, double x1, double x2)
{
    if (in_nr != num_root) return 0;

    switch(num_root)
    {
    case INF:
        return 1;

    case 0:
        return 1;

    case 1:
        if (Eq(x1, inx1)) return 1;
        else              return 0;

    case 2:
        if ((Eq(x1, inx1) && Eq(x2, inx2)) || (Eq(x1, inx2) && Eq(x2, inx1)))
            return 1;
        else
            return 0;

    default:
        return 0;
    }
}


void PrintFail(FILE *out, double a, double b, double c,
               int    in_nr, double inx1, double inx2,
               int num_root, double   x1, double   x2)
{
    fprintf(out, "a = %.2lf b = %.2lf c = %.2lf num_root = %d x1 = %.2lf x2 = %.2lf "
            " Test failed.\n"
            "Function returned num_root = %d, x1 = %.2lf, x2 = %.2lf",
            a, b, c, in_nr, inx1, inx2, num_root, x1, x2);
}


void PrintSuccess(FILE *out, double a, double b , double c,
                  int num_root, double x1, double x2)
{
    fprintf(out, "a = %.2lf b = %.2lf c = %.2lf num_root = %d x1 = %.2lf x2 = %.2lf "
            " Test passed successfully.\n", a, b, c, num_root, x1, x2);
}


void PrintInpError(FILE *out, char *buf)
{
    int i = 0;

    while (buf[i] != '\n' && buf[i] != '\0') i++;

    if (buf[i] == '\n') buf[i] = '\0';

    fprintf(out, "%s Input Error.\n", buf);
}



