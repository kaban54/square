#include"square.h"


const double Epsilon = 0.001;


int SolveSquare(struct coefficients coefs, struct solution *psol)
{

    double a = coefs.a,
           b = coefs.b,
           c = coefs.c;

    int num_root = 0;

    double *px1 = &(psol -> x1),
           *px2 = &(psol -> x2);


    assert (px1 != NULL);
    assert (px2 != NULL);

    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));


    double d = NAN;


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

        if (d < 0) num_root = ZERO;
        else if (IsZero(d))
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

    psol -> num_root = num_root;
    return num_root;
}


int SolveLinear(double a, double b, double *px)
{
    assert (px != NULL);

    assert (isfinite(a));
    assert (isfinite(b));


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
    if (fabs(x) < Epsilon) return 1;
    else                   return 0;
}

int Eq(double x, double y)
{
    if (IsZero(x - y)) return 1;
    else               return 0;
}



int Input(char *name, struct coefficients *pcoefs)
{
    FILE *in = fopen(name, "r");
    if (in == NULL) return INPUT_ERROR;

    if (NUM_ARGS != fscanf (in, "%lf %lf %lf", &(pcoefs -> a), &(pcoefs -> b), &(pcoefs -> c)))
    {
        fclose(in);
        return INPUT_ERROR;
    }

    fclose(in);

    return 0;
}

int Output(char *name, struct solution sol)
{

    int num_root = sol.num_root;
    double x1 = sol.x1,
           x2 = sol.x2;


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


