#include <stdio.h>
#include <math.h>

int main()
{

    // example 1 -----------------------
    // step 1) declare variables
    int a;
    float b, c;

    // step 2) init variables
    a = 10;
    b = 1.2;
    c = 2.4;

    printf("%d, %.1f, %.1f\n", a, b, c);

    // example 2 -----------------------
    // declare and init at the same line
    char d = 'X'; 

    printf("%c\n", d);




    return 0;
}

/*
IMPORTANCE!!! -----------------------------------------------
1) All variables need to be declared first before use.
2) You can declare multiple variables in 1 line
3) You can declare and init at the same line.
-------------------------------------------------------------
*/