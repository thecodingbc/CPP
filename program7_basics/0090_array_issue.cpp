#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main()
{


    int a[3] = {0};

    for(int i = 0; i < 7; i++)
        printf("%d\n", a[i]);

    /*
    ISSUE 1: 
    C/C++ will not report any error even you exceeds arrays' size. Insidious issue.

    ISSUE 2:
    You need to know the array size when you write your program.
    This is illegal.
    */
//    int x = 5;
//    int b[x] = {0};

    // Because of this, we call it static array. 
    // dynamic array. -> vector

    return 0;
}
