#include <bits/stdc++.h>
using namespace std;


// enum is a special class, it has a fixed set of values.

enum Colors {
    Blue,       // by default, each enum has a int value, starting from 0
    Green,      // 1
    Yellow,
    Orange,
    Red         // 4
};


enum Directions {
    North = 25, // you require the element's value start from 25
    South,
    East, 
    West    // 28
};


int main() {

    cout << "Blue: " << Blue << endl;
    cout << "Green: " << Green << endl;
    cout << "Yellow: " << Yellow << endl;
    
    cout << "North: " << North << endl;
    cout << "South: " << South << endl;

    int i = North;
    cout << "Wind direction: " << i << endl;


    return 0;
}

/*
IMPORTANCE!!! ------------------------------
standard enum:
1) implcitly convert to int
---------------------------------------------


*/