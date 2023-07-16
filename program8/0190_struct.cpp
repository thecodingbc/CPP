#include <bits/stdc++.h>
using namespace std;


struct Test1 {
    int x;  // x is public
};

class Test2 {
    int x; // x is private
};


int main() {

    Test1 t1;
    t1.x = 20;

    Test2 t2;
    // t2.x = 20; // error!

    return 0;
}