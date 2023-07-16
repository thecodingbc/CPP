/*
HOMEWORK
--------------
Requirement
--------------
Read from console a 3 digit int number, reverse the number and print it to the console

--------------
Example
--------------
Input: 
127
Output: 
721
*/

#include <stdio.h>
#include <math.h>

int main()
{


    int n;
    scanf("%d", &n);

    printf("%d%d%d\n", n % 10, n / 10 % 10, n / 100);

    int a = 100 * (n % 10) + 10 * (n / 10 % 10) + n / 100;
    printf("%d\n", a);



    return 0;
}
