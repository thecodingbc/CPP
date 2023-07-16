/*
--------------
Requirement
--------------
Read 2 numbers from console, swap the 2 values and print to console

--------------
Example
--------------
Input: 
10 12
Output: 
12 10
*/


#include <stdio.h>
#include <math.h>

int main()
{

    int a, b;
    scanf("%d%d", &a, &b);


    // // Solution 1-----------------
    // int t = a;
    // a = b;
    // b = t;

    // Solution 2) Requirement: swap without using a 3rd var t --------------
    a = a + b;
    b = a - b;
    a = a - b;

    /*
    initially            a = a0         b = b0
    after a = a + b      a = a0 + b0    b = b0
    after b = a - b      a = a0 + b0    b = a0
    after a = a - b      a = b0         b = a0
    */



    printf("%d %d\n", a, b);    




    // // Best solution ---------- 
    // printf("%d %d", b, a);


    return 0;
}


/*
IMPORTANCE!!! -----------------------------------------------
CP is not to show your programming skills
Keep It Simple and Stupid (KISS)
-------------------------------------------------------------

*/