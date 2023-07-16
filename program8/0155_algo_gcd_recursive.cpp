/*
GreatestCommonDivisor - GCD
Use below recursive algo to find the Greatest Common Divisor (GCD) of 2 numbers.
gcd(a,b) = gcd(b,a % b)  
Condition: a > b
*/


























#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0) // base case
    {
        return b;
    }
    else // recursive call
    {
        return gcd(b, a % b);
    }
}



int main() {

    int m, n;

    cin >> m >> n;

    cout << gcd(m, n);

    return 0;
}