#include "square.h"


int Input(double* a, double* b, double* c)
{
    printf ("Enter a, b, c:\n");
    if (NUM_ARGS != scanf ("%lf%lf%lf", a, b, c))
    {
        printf ("Input Error");
        return INPUT_ERROR;
    }
    return 0;
}

int Output(int num_root, double x1, double x2)
{
    switch(num_root)
    {

        case 0:
            printf("No roots\n");
            break;

        case 1:
            printf("x = %lf\n", x1);
            break;

        case 2:
            printf("x1 = %lf\nx2 = %lf\n", x1, x2);
            break;

        case INF:
            printf("x is any number\n");
            break;

        default:
            printf("Output Error");
            return OUTPUT_ERROR;
    }
    return 0;
}
