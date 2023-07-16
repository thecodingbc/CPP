/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1251
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1359_useco22_b_cow_colledge.txt", "r", stdin);

    ll n;
    cin >> n;

    ll arr[n];
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    ll totalFee = 0LL;
    ll bestFee = 0LL;

    for(ll i = 0; i < n; i++) {

        ll tmp = arr[i] * (n - i);

        if(tmp > totalFee) {
            totalFee = tmp;
            bestFee = arr[i];
        }
    }
    
    cout << totalFee << " " << bestFee << endl;

    return 0;
}