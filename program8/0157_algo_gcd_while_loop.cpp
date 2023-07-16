/*
GreatestCommonDivisor - GCD
Use below recursive algo to find the Greatest Common Divisor (GCD) of 2 numbers.
gcd(a,b) = gcd(b,a % b)  
Condition: a > b
*/

#include <bits/stdc++.h>
using namespace std;

// non recursive algo

int gcd(int a, int b)
{

    /*
    As long as the reminder b doesn't equale to 0, then we:
    1) assign the old b to new a
    2) assign b % a to new b
    3) loop until reminder (new b) is 0
    */
    while(b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}



int main() {

    int m, n;

    cin >> m >> n;

    cout << gcd(m, n);

    return 0;
}