/*
Requirement:
There are multiple lines of inputs.
Each line contains 2 int numbers, n and m, n < m < 10^6
Use freopen to store input in a file.

Calculate:
1/n^2 + 1/(n+1)^2 + .... + 1/m^2

Sample:

Input:
2 4
65536 655360

Output:
0.42361
0.00001


Condition:
n <= 10^6

*/


#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{


    freopen("0052_input.txt", "r", stdin);

    int n, m;

    while(scanf("%d%d", &n, &m) == 2) {

        float result = 0;

        for(int i=n; i<=m; i++) {
            result += 1.0 / ((long long)i * i);
        }

        /*
        1) Because i can be 10^6, so i^2 will exceed int range
        so we have to cast the result to long long type

        2) 1 /10 gives you a int result
           1.0 / 10 gives you a float result
           So, we have to use 1.0
        */

        printf("%.5f\n", result);

    }




    return 0;
}
