/*
https://codebreaker.xyz/problem/wabot

1) we must handle lower level modules first, before we handle higher level modules.
-> map: 
   key: level (ll)

2) For all modules within the same level, they also need to be sorted, so that I keep the most complex module within the level
   multiset<ll>

map<ll, multiset<ll>> m;



*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1339_codebreaker_wabot.txt", "r", stdin); // Remove this line before your submit

    ll n;
    cin >> n;

    map<ll, multiset<ll>> m;

    ll l, c;

    for(ll i = 0; i < n; i++){
        cin >> l >> c;
        m[l].insert(c);
    }

    ll total_time = 0;

    //loop all multiset from low level to high level
    for(auto p : m) {

        ll level = p.first;
        multiset<ll> ms = p.second;

        // ms contains the complexities for all modules with same level
        ll x, y;
        while(ms.size() > 1) {
            // remove the 2 modules with smallest complexity
            x = *begin(ms);
            ms.erase(begin(ms));

            y = *begin(ms);
            ms.erase(begin(ms));

            // integrate them requires x + y seconds
            total_time += x;
            total_time += y;

            // they form a new module of a upper level
            m[level + 1].insert(x + y);
        }
    }

    cout << total_time << endl;

    return 0;
}