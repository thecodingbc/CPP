/*
--------------
Requirement
--------------

https://psle-math.com/student/test/chicken-and-rabbit-problem

There are a total of n Chickens and Rabbits on a farm. Given that the total number of legs on the farm is m, find the number of Chickens and rabbits.

--------------
Example
--------------
Input: 
14 32
Output: 
12 2

Input: 
10 16
Output: 
No Answer
*/



#include <stdio.h>
#include <math.h>


/*
 a chicken , b rabbits
 a + b = n
 2a + 4b = m

 a = (4n-m)/2
 b = n - a
*/

int main()
{

    int a, b, n, m;
    scanf("%d %d", &n, &m);

    a = (4 * n - m) / 2;
    b = n - a;


    // Solution 1) 
    if (m % 2 == 1 || a < 0 || b < 0) {
        printf("No answer\n");
    }
    else {
        printf("%d %d", a, b);
    }


    /*
    1) boolean expression:
    || -> or
    && -> and
    !  -> not

    2) use parentheses after if
    3) user {} to begin a if block / else block


    */


    // Solution 2) if there is only 1 line in if body / else body, {} can be ignored.
    if (m % 2 == 1 || a < 0 || b < 0)
        printf("No answer\n");
    else
        printf("%d %d", a, b);


    // Python:
    // actual_diff = (a - b) if a > b else (b - a)

    // Solution 3) ternary opeartor
    (m % 2 == 1 || a < 0 || b < 0) ? printf("No answer\n") : printf("%d %d", a, b);


    return 0;
}


/*
unary operator
int i = 10;
i++; 
--k;
k += 10;


binary operator
c=a+b;

*/