/*
https://codebreaker.xyz/problem/pairsums

summary:

a list of numbers
find all combinations any 2, whose sum is odd

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


void setIO(string s) {
    freopen((s + ".IN").c_str(), "r", stdin);
    freopen((s + ".OUT").c_str(), "w", stdout);
}

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1204_codebreaker_pairsums.txt", "r", stdin); // Remove this line before your submit

    ll n;
    cin >> n;

    ll arr[n];
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll result = 0LL;
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % 2 != 0) {
                result++;
            }
        }
    }
    cout << result << endl;
    return 0;
}