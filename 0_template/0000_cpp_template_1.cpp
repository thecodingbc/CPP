#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    freopen("test_data_input.txt", "r", stdin); // Remove this line before your submit

    int tc_count;  // number of test cases
    scanf("%d", &tc_count);

    while (tc_count--)  // shortcut to repeat until 0
    {

        // read data per test case
        int a, b;
        scanf("%d %d", &a, &b);

        // quite often, you need to use long long time
        ll c, d;
        scanf("%lld %lld", &c, &d);

        // here begins your logic
        printf("%d\n", a + b);
        printf("%lld\n", c - d);

        



    return 0;
}