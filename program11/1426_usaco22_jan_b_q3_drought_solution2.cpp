/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1181

Q Description:

You are given a vector of numbers.
For example:

    8 10 5
->  8 8  3      -> 2 * 2 = 4
->  3 3  3      -> 2 * 5 = 10  ==> 14

    4 6 4 4 6 4
->  4 4 2 4 6 4 -> 2 * 2 = 4
->  4 4 2 2 4 4 -> 2 * 2 = 4
->  4 4 2 2 2 2 -> 2 * 2 = 4

reverse(begin(v), end(v))

-> 2 2 2 2 4 4
-> 2 2 2 2 2 2  -> 2 * 2 = 4


You can lower any adjacent 2 numbers together
Your goal is to make all numbers same

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1424.txt", "r", stdin);

    ll n;
    cin >> n;

    for(ll i = 0; i < n; i++) {

        ll size;
        cin >> size;

        vector<ll> v(size);

        for(ll j = 0; j < size; j++) {
            cin >> v[j];
        }

        ll total_lowered_cnt = 0;

        for(ll j = 0; j < 2; j++) {

            /*
            because you need to lower v[k] & v[k+1], so k < size-1, not <=
            because I compare v[k] vs v[k-1], so k starts from 1
            */
            for(ll k = 1; k < size - 1; k++) {
                if(v[k] > v[k-1]) { // lower pair v[k] & v[k+1]
                    ll dif = v[k] - v[k-1];
                    total_lowered_cnt += 2 * dif;
                    v[k] = v[k-1];
                    v[k+1] -= dif;
                }
            }

            if(v[size-1] > v[size-2]) { // compare the last 2
                total_lowered_cnt = -1;
                break;
            }

            // now v is non-increasing
            reverse(begin(v), end(v));

            // now v is non-decreasing
        }

        if(v[0] < 0) {
            total_lowered_cnt = -1;
        }

        cout << total_lowered_cnt << endl;

    }

    return 0;
}