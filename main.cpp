#include "square.h"

//doxygen

int main(void)
{

    #ifdef NDEBUG


    struct coefficients coefs = {NAN, NAN, NAN};
    struct solution     sol   = {  0, NAN, NAN};

    char inp_file_name[MAX_LEN], out_file_name[MAX_LEN];

    printf (" Input file name: ");
    scanf  ("%s", inp_file_name);
    printf ("Output file name: ");
    scanf  ("%s", out_file_name);


    if (Input(inp_file_name, &coefs))
    {
        return INPUT_ERROR;
        printf ("Input Error");
    }


    sol.num_root = SolveSquare(coefs, &sol);


    if (Output(out_file_name, sol))
    {
        return OUTPUT_ERROR;
        printf ("Output Error");
    }

    return 0;

    #else                                //cmd line arguments

    char inp_file_name[MAX_LEN] = "";
    char out_file_name[MAX_LEN] = "";

    printf (" Input test file name: ");
    scanf  ("%s", inp_file_name);
    printf ("Output test file name: ");
    scanf  ("%s", out_file_name);

    FILE *inp_file = NULL;
    FILE *out_file = NULL;

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


