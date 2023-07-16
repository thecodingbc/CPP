#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main()
{
    
    int i1[5]; // declare only, must specify size, unless you init it.

    int i2[] = {1, 2, 3, 4, 5}; // declare and init, size is 5

    // copy array --------------------------------------------
    // requirement: copy the value from i2 to i1

    // i1 = i2; ERROR! ERROR! You cannot assign an array value to an array variable, due to a peculiar relationship betwen pointer and array.

    printf("Solution 1) copy to array i1 using plain old solution: \n");
    for(int i = 0; i < 5; i++)
        i1[i] = i2[i];
    
    for(int i = 0; i < 5; i++)
        printf("%d\n", i1[i]);

    printf("How many bytes does each int value take: %d \n", sizeof(int)); //sizeof(int) returns 4, meaning each int takes 4 bytes size in memory


    printf("Solution 2) copy to array i1 using memcpy function: \n");
    int i3[] = {6, 7, 8, 9, 10};

    memcpy(i1, i3, sizeof(int) * 3);
    /*
    IMPORTANCE!!! ------------------------
    1) memcpy requires string.h header file
    2) memcpy means 'memory copy', which means, 'directly copy bytes from memory'
    3) 3 args: a) desination   -> i1                -> copy to i1 array
               b) source       -> i3                -> copy from i3 array
               c) bytes amount -> sizeof(int) * 3   -> copy 12 bytes from i3 to i1
    --------------------------------------
    */

    for(int i = 0; i < 5; i++)
        printf("%d\n", i1[i]);



    return 0;
}