#include <bits/stdc++.h>
using namespace std;
  
int main()
{

    // example 1: swap 2 int values -----------------------------

    int a = 10;
    int b = 20;
    cout << "Value of a before: " << a << endl;
    cout << "Value of b before: " << b << endl;
  
    swap(a, b);

    cout << "Value of a now: " << a << endl;
    cout << "Value of b now: " << b << endl;

    cout << "---------------------" << endl;

    // example 2: swap 2 string values -----------------------------

    string c = "Hello";
    string d = "C++";

    cout << "Value of c before: " << c << endl;
    cout << "Value of d before: " << d << endl;

    swap(c, d);
    
    cout << "Value of c now: " << c << endl;
    cout << "Value of d now: " << d << endl;

    return 0;
}


