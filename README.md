Program solves quadratic equations.

Build:
    1) Download source files
    2) make square
    3) square.exe input_file_name output_file_name

input file:
    file contains 3 nubers: a b c - coefficients of the equation



Testmode:
Remove -DNDEBUG flag from Makefile to use testmode

test input file:
    each line contains six numbers: a b c num_root x1 x2
    a, b, c - equation coefficients
    num_root - number of roots (0, 1, 2 or -1 if infinite number of roots)
    x1, x2 - roots of the equation (use 0 if there are no roots)
        
