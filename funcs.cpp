#include"square.h"


const double Zero = 0.000001;


int SolveSquare(double a, double b, double c, double *px1, double *px2)
{

    assert (px1 != NULL);
    assert (px2 != NULL);

    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    int num_root = 0;
    double d = 0;


    if(IsZero(a)) num_root = SolveLinear(b, c, px1);

    else if(IsZero(c))
    {
        *px1 = 0;
        num_root = SolveLinear(a, b, px2);
        num_root = (num_root == INF) ? INF : num_root + 1;
    }
    else
    {
        d = b * b - 4 * a * c;
        if(d < 0) num_root = ZERO;
        else if(IsZero(d))
        {
            num_root = ONE;
            *px1 = -b / (2 * a);
        }
        else
        {
            num_root = TWO;
            d = sqrt (d);

            *px1 = (-b - d) / (2 * a);
            *px2 = (-b + d) / (2 * a);
        }
    }
    return num_root;
}


int SolveLinear(double a, double b, double *px)
{
    int num_root = ZERO;

    if(IsZero(a))
    {
        if(IsZero(b)) num_root =  INF;
        else          num_root = ZERO;
    }
    else
    {
        num_root = ONE;
        *px = -b / a;
    }
    return num_root;
}

int IsZero(double x)
{
    if (fabs(x) < Zero) return 1;
    else                return 0;
}

int Eq(double x, double y)
{
    if (IsZero(x - y)) return 1;
    else               return 0;
}



int Input(char *name, double* a, double* b, double* c)
{
    FILE *in = fopen(name, "r");
    if (in == NULL) return INPUT_ERROR;

    if (3 != fscanf (in, "%lf%lf%lf", a, b, c))
    {
        fclose(in);
        return INPUT_ERROR;
    }

    fclose(in);

    return 0;
}

int Output(char *name, int num_root, double x1, double x2)
{
    FILE *out = fopen(name, "w");
    if (out == NULL) return OUTPUT_ERROR;

    switch(num_root)
    {

        case 0:
            fprintf (out, "No roots\n");
            break;

        case 1:
            fprintf (out, "x = %lf\n", x1);
            break;

        case 2:
            fprintf (out, "x1 = %lf\nx2 = %lf\n", x1, x2);
            break;

        case INF:
            fprintf (out, "x is any number\n");
            break;

        default:
            fprintf (out, "Output Error");
            fclose(out);
            return OUTPUT_ERROR;
    }

    fclose(out);

    return 0;
}


