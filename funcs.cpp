#include"square.h"


const double Zero = 0.000001;


int SolveSquare(double a, double b, double c, double *px1, double *px2)
{
    int num_root = 0;
    double d = 0;

    if(IsZero(a)) num_root = SolveLinear(b, c, px1);

    else if(IsZero(c))
    {
        *px1 = 0;
        num_root = SolveLinear(a, b, px2)
        num_root = (num_root == INF) ? INF : num_root + 1;
    }
    else
    {
        d = b * b - 4 * a * c;
        if(d < 0) num_root = 0;
        else if(IsZero(d))
        {
            num_root = 1;
            *px1 = -b / (2 * a);
        }
        else
        {
            num_root = 2;
            d = sqrt (d);

            *px1 = (-b - d) / (2 * a);
            *px2 = (-b + d) / (2 * a);
        }
    }
    return num_root;
}


int SolveLinear(double a, double b, double *px)
{
    int num_root = 0;

    if(IsZero(a))
    {
        if(IsZero(b)) num_root = INF;
        else       num_root = 0;
    }
    else
    {
        num_root = 1;
        *px = -b / a;
    }
    return num_root;
}

int IsZero(double x)
{
    if (fabs(x) < ZERO) return 1;
    else return 0;
}
