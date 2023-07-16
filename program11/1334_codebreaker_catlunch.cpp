/*
https://codebreaker.xyz/problem/catlunch
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1334_codebreaker_catlunch.txt", "r", stdin);

    ll n, k;
    cin >> n >> k;
    ll t;

    ll max_taste = 0LL, taste = 0LL;

    multiset<ll, greater<ll>> v;

    for(ll i = 0; i < n; i++) {

        /*
        So, next we let the cat to finish all n fish, 
        but before it can eat the ith fish, we must make sure the v's size is less than k
        */

        if(v.size() == k) {
            taste += *begin(v);
            v.erase(begin(v));
        }

        // now the cat can eat this ith fish
        cin >> t;

        if(t >= 0) {
            taste += t;
            cout << t << " : " << taste << " ";
            max_taste = max(max_taste, taste);
            cout << max_taste << endl;
            continue;
        }

        v.insert(t);

        cout << "v has: ";
        for(ll x : v) {
            cout << x << " ";
        }

        cout << endl;
    }



    cout << max_taste << endl;

    return 0;
}