/*
Requirement:
user types random number of integers in 1 line
You print out their min / max / average
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{

    // int a, b;

    // int x = scanf("%d%d", &a, &b);
    // printf("read in var count: %d\n", x);
    // printf("They are: %d %d\n", a, b);

    /*
    IMPORTANCE!!! ----------------------------
    scanf returns the total count of the successfully-assigned var count
    ------------------------------------------
    */

    int x, n = 0, min = INT_MAX, max = INT_MIN, s = 0;
    /*
    IMPORTANCE!!! ----------------------------
    limits.h defines min int value and max int value
    ------------------------------------------
    */

   while(scanf("%d", &x) == 1) {
       s += x;
       if(x < min) min = x;
       if(x > max) max = x;
       n++;
   }

   printf("%d %d %.3f\n", min, max, (double)s/n); 

    return 0;
}


/*
IMPORTANCE!! ----------------------
how to stop input from console? 
Win: Enter -> Ctrl + Z -> Enter
Mac: Ctrl + D
-----------------------------------


*/