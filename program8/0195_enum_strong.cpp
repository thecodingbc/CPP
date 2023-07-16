#include <bits/stdc++.h>
using namespace std;


// enum is a special class, it has a fixed set of values.

enum class Colors {
    Blue,       // by default, each enum has a int value, starting from 0
    Green,      // 1
    Yellow,
    Orange,
    Red         // 4
};


enum class Directions {
    North = 25, // you require the element's value start from 25
    South,
    East, 
    West    // 28
};


int main() {

    // explicitly type casting
    cout << "Blue: " << static_cast<int>(Directions::North) << endl;

    return 0;
}

/*
IMPORTANCE!!! ------------------------------
standard enum:
1) implcitly convert to int
---------------------------------------------


*/