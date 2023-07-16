#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main()
{


    // memset helps quickly assign some init value to some array
    printf("\n example 1: init a char array -----------------\n");

    char c1[5];
    memset(c1, 'A', sizeof(char) * 5);
    /*
    IMPORTANCE!!! ------------------------
    1) memset requires string.h header file
    2) memset means 'memory set', which means, 'directly set bytes value'
    3) 3 args: a) desination   -> c1                 -> set to c1 array
               b) value        -> 'A'               
               c) bytes amount -> sizeof(char) * 5   -> set 5 bytes
    --------------------------------------
    */

    for(int i =0; i < 5; i++)
        printf("%c\t", c1[i]);


    printf("\n example 2: init a int array using 0-----------------\n");
    int i1[5];
    memset(i1, 0, sizeof(int) * 5);

    for(int i =0; i < 5; i++)
        printf("%d\t", i1[i]);


    printf("\n example 3: init a int array using 1-----------------\n");
    memset(i1, 1, sizeof(int) * 5);

    for(int i =0; i < 5; i++)
        printf("%d\t", i1[i]);

    /*
    convert decimal 16843009 to binary, you get: 00000001000000010000000100000001

    IMPORTANCE!!! ----------------------------
    because:
    memset sets value byte by byte.
    one int takes 4 bytes.

    conclusion:
    if you use memset to a int array, you can only set its value to 0
    ------------------------------------------


    */


    return 0;
}