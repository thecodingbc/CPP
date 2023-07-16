/*
Requirement:
Calculate the last 6 digits of S
S = 1! + 2! + 3! + 4! + ... + n!
n! = 1 * 2 * 3 * ... * n

Sample:

Input: 
10

Output:
37913

Condition:
n <= 10^6

*/


#include <stdio.h>
#include <math.h>

int main()
{


    // [VERSION 1]
    // int x = 1;
    // for(int i = 1; i <= 13; i++)
    // x *= i;

    // printf("%d\n", x);


    /*
    10! 3,628,800
    11! 39,916,800
    12! 479,001,600
    13! 1,932,053,504
    */

    // [VERSION 2]
    // long long x = 1;
    // for(int i = 1; i <= 20; i++)
    // x *= i;

    // printf("%lld\n", x);

    /*
    20! 2,432,902,008,176,640,000
    */


   /*
    12,345,678 = 12,000,000 + 678
    12,345,678 * x = 12,000,000 * x + 678 * x
   */


    // [VERSION 3]
    // int n;
    // scanf("%d", &n);

    // int result = 0;

    // // calculate the factorial from 1 to n
    // for(int i =1; i <=n; i++) {

    //     // calculate factorial for i

    //     int z = 1;
    //     for(int j = 1; j <= i; j++) {
    //         z %= 1000000; // always remove those digits higher than 1,000,000
    //         z *= j;
    //     }

    //     // add factorial of i to result
    //     result += z;
    // }

    // printf("%d\n", result%1000000);


    // time complexity

    /*
    1 + 2 + 3 +... + n 
    = (1 + n) * n / 2 
    = 1/2*n^2 + 1/2*n

    When we analyze algo time complexity, we only look at the highest entry, and remove the coefficient
    O(n^2)

    */



    // [VERSION 4]
    // int n;
    // scanf("%d", &n);

    // int result = 0;
    // int z = 1;

    // // calculate the factorial from 1 to n
    // for(int i =1; i <=n; i++) {

    //     // calculate factorial for i
    //     z %= 1000000; // always remove those digits higher than 1,000,000
    //     z *= i;

    //     // add factorial of i to result
    //     result += z;
    // }

    // printf("%d\n", result%1000000);

    /*
    time complexity : O(n)
    */


    // [VERSION 5]
    int n;
    scanf("%d", &n);

    int result = 0;
    int z = 1;

    if(n > 23) n=24;

    // calculate the factorial from 1 to n
    for(int i =1; i <=n; i++) {

        // calculate factorial for i
        z %= 1000000; // always remove those digits higher than 1,000,000
        z *= i;

        // add factorial of i to result
        result += z;
    }

    printf("%d\n", result%1000000);


    /*
    
    max : 24 -> 0*n+24

    time complexity : O(1)
    */




    return 0;
}