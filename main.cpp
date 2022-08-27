#include "square.h"


int main(int argc, char *argv[])
{

    #ifdef NDEBUG

    if (argc < 3)
    {
        prinitf("Not enough arguments.");
        return ARG_ERROR;
    }

    struct coefficients coefs {};
    struct solution     sol   {};

    char inp_file_name[MAX_LEN] = "";
    char out_file_name[MAX_LEN] = "";

    strcpy(inp_file_name, argv[1]);
    strcpy(out_file_name, argv[2]);


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

    #else

    if (argc < 3)
    {
        printf("Not enough arguments.");
        return ARG_ERROR;
    }


    char inp_file_name[MAX_LEN] = "";
    char out_file_name[MAX_LEN] = "";

    strcpy(inp_file_name, argv[1]);
    strcpy(out_file_name, argv[2]);


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


