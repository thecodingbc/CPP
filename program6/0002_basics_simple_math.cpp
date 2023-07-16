#include <stdio.h>
#include <math.h>

int main()
{

    /*
    IMPORTANCE!!! -----------------------------------------------
    1) C/C++ requires strict match between the placeholder and the value.
    1 + 2 = 3  -> int type -> %d
    1 - 2 = -1 -> int type -> %d
    1 * 2 = 2  -> int type -> %d
    */

    printf("Math: + - * ------------------------\n");
    printf("1 + 2 = %d\n", 1 + 2); // 3
    printf("1 - 2 = %d\n", 1 - 2); // -1
    printf("1 * 2 = %d\n", 1 * 2); // 2


    /*
    When both dividend and divisor are int, then '/' gives you a int quotient -> %d
    When either dividend or divisor is float, then '/' gives you a float quotient -> %f
    */
    printf("Math: / ------------------------------\n");
    printf("1 / 2 = %d\n", 1 / 2); // 0
    printf("1 %% 2 = %d\n", 1 % 2); // 1
    printf("1.0 / 2 = %.1f\n", 1.0 / 2); // 0.5

    printf("%f\n", 1 + 2 * sqrt(3) / (5 - 0.1));

    return 0;
}


/*
IMPORTANCE!!! -----------------------------------------------
1) Use %% to print % in printf
-------------------------------------------------------------
*/