/*
You have n lights, 1 - n.
1st person turn on all lights
2nd person turn off  2 / 4 / 6 ... lights
3rd person turn on 3 / 6 / 9 .... lights
4th person turn off 4 / 8 / 12 ... lights

There are in total K person, find out the 'on' lights index.

Input: n and k
7 3

Output: 
1 5 6 7 

k <= n <= 1000

*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main()
{


    // Step 1）Prepare data --------------------------
    int n, k;
    scanf("%d%d", &n, &k);

    /*
    declare an bool array
    set size=1001, as max n can be 1000, and I keep the 1st one unused.
    I only init the 1st value to false
    the remaining 1000 values will be set to false automaically by C/C++ 
    */
    bool l[1001] = {false};


    // Step 2) mimic the process ---------------------

    // loop all persons from 1 to k
    for(int i = 1; i <=k; i++) // loop k person
        for(int j = 1; j <= n; j++) // loop n lights
            if(j % i == 0)
                l[j] = !l[j];

    
    // Step 3) check the result ------------------------
    for(int i = 1; i <=n; i++)
        if(l[i])
            printf("%d\n", i);
            

    return 0;
}