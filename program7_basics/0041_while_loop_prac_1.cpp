/*

Homework
--------------
Requirement
--------------
For any integer n
if it is odd, change it to 3n+1
if it is even, change it to n/2

Change n until n becomes 1,
Print how many changes times it requires.


Condition:
n <= 10^9

*/


#include <stdio.h>
#include <math.h>

int main()
{

    // int n, count = 0;
    // scanf("%d", &n);

    long long n;
    int count = 0;
    scanf("%lld", &n);


    while(n > 1) {
        if(n % 2 == 1)
            n = n * 3 + 1;
        else
            n /= 2;

        count++;
    }

    printf("%d\n", count);

    return 0;
}


/*
IMPORTANTCE!!! ------------------------------------------
1) int variable takes 4 bytes, which is 32 bits.
2) 1st bit is used a sign. 0 means positive number / 1 means negative number
3) 31 remaining bits are used to store a binary number, ranging from 0.....0 to 1......1
   convert the binary number to decimal number, ranging from 0 to 2^31-1
   1   -> 2^1-1 = 1
   11  -> 2^2-1 = 3
   111 -> 2^3-1 = 7
   ...
   11...1 -> 2^31-1 

4) consider the sign bit in the front, so
   int var range is [-2^31, 2^31-1]
   2^3 = 8
   2^10 = 1024  equals to 10^3
   2^30 == 10^9
   2^31 == 2*10^9
   [-2,000,000,000      ,   2,000,000,000 ]

int var range is negative 2 billion to positive 2 billion


5) C/C++ has a data type called 'long long', which takes 8 bytes, which is 64 bits. 

[HOMEWORK] tell me the range of 'long long'
long long var range is: [-2^63, 2^63-1]
2^3=8, 
2^10=1024=10^3,
2^60=10^18, 
2^63=8*10^18

long long var range is: [-9*10^18, 9*10^18],    
---------------------------------------------------------





*/