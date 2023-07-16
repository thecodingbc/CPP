/*
--------------
Requirement
--------------
Use 2 solutions to find all 4 digit square numbers in format like aabb.


if(sqrt(n) == floor(sqrt(n)))
    printf("%d\n", n);



*/


#include <stdio.h>
#include <math.h>

int main()
{

    for(int i = 1; i <= 9; i++ ) 
    for(int j = 0; j <= 9; j++) {
        int n = i * 1000 + i * 100 + j * 10 + j;
        if(sqrt(n) == floor(sqrt(n))) printf("%d\n", n);
    }


    return 0;
}