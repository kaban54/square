#include "square.h"

#define NDEBUG

int main(void)
{

    #ifdef NDEBUG

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int num_root = 0;

    char inp_file_name[MAX_LEN], out_file_name[MAX_LEN];

    printf (" Input file name: ");
    scanf  ("%s", inp_file_name);
    printf ("Output file name: ");
    scanf  ("%s", out_file_name);


    if (Input(inp_file_name, &a, &b, &c))
    {
        return INPUT_ERROR;
        printf ("Input Error");
    }


    num_root = SolveSquare(a, b, c, &x1, &x2);


    if (Output(out_file_name, num_root, x1, x2))
    {
        return OUTPUT_ERROR;
        printf ("Output Error");
    }

    return 0;

    #else

    char inp_file_name[MAX_LEN], out_file_name[MAX_LEN];

    printf (" Input file name: ");
    scanf  ("%s", inp_file_name);
    printf ("Output file name: ");
    scanf  ("%s", out_file_name);

    FILE *inp_file, *out_file;

    if ((inp_file = fopen(inp_file_name, "r")) == NULL)
    {
        printf("Input Error");
        return  INPUT_ERROR;
    }
    if ((out_file = fopen(out_file_name, "w")) == NULL)
    {
        printf("Output Error");
        return  OUTPUT_ERROR;
    }

    SquareTest (inp_file, out_file);

    fclose (inp_file);
    fclose (out_file);

    return 0;

    #endif
}


