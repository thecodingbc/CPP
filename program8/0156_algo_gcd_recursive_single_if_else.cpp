/*
GreatestCommonDivisor - GCD
Use below recursive algo to find the Greatest Common Divisor (GCD) of 2 numbers.
gcd(a,b) = gcd(b,a % b)  
Condition: a > b
*/

#include <bits/stdc++.h>
using namespace std;

// 辗转相除法 / 欧几里得算法

int gcd(int a, int b)
{
    // Version 0
    // if (a % b == 0) // base case
    // {
    //     return b;
    // }
    // else // recursive call
    // {
    //     return gcd(b, a % b);
    // }

    // Version 1
    // boolean expression ? true_case : false_case;
    // return (a % b == 0) ? b : gcd(b, a % b);

    // Version 2
    return (a % b) ? gcd(b, a % b) : b;

}



int main() {

    int m, n;

    cin >> m >> n;

    cout << gcd(m, n);

    return 0;
}