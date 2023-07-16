#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("test_data_input.txt", "r", stdin); // remove this line when you submit online

    int tc_count; // number of test cases
    scanf("%d", &tc_count);

    while(tc_count--) { //shortcut to repeat until 0

        // read data per test case
        int a, b;
        scanf("%d %d", &a, &b);

        // quite often, you need to use long long type
        long long c, d;
        scanf("%lld %lld", &c, &d);

        // here begins your logic

        printf("%d\n", a + b);
        printf("%lld\n", c - d);

    }



    return 0;
}

/*

1) 1st line: total count of test cases 'n', indicating the number of test cases
2) 'n' lines: each line contains sevral numbers, each line represent a test case.


*/