#include "square.h"


main(void)
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int num_root = 0;


    if(Input(&a, &b, &c)) return INPUT_ERROR;

    printf("%.2lfx^2 + %.2lfx + %.2lf = 0\n", a, b ,c);

    num_root = SolveSquare(a, b, c, &x1, &x2);

    if(Output(num_root, x1, x2)) return OUTPUT_ERROR;

    return 0;
}

