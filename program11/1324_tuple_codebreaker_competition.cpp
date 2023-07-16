/*
https://codebreaker.xyz/problem/competition
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool sort_by_diff(tuple<ll, ll, ll>& left, tuple<ll, ll, ll>& right) {
    return get<2>(left) < get<2>(right);
}

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1324_codebreaker_competition.txt", "r", stdin); // Remove this line before your submit

    // step 1) read data in
    ll n, a, b;
    cin >> n >> a >> b;

    ll phy[n], bio[n];
    for(ll i = 0; i < n; i++) {
        cin >> phy[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> bio[i];
    }    


    // step 2) I need to sort all values of phy[i] - bio[i]

    vector<tuple<ll, ll, ll>> v;
    for(ll i = 0; i < n; i++) {
        v.push_back(make_tuple(phy[i], bio[i], phy[i] - bio[i]));
    }

    // step 3) sort v using 3rd field
    sort(begin(v), end(v), sort_by_diff);

    ll sum = 0;
    for(ll i = 0; i < b; i++) {
        sum += get<1>(v[i]); //first a students, use their bio score
    }

    for(ll i = b; i < n; i++) {
        sum += get<0>(v[i]); //remaing(b) students, use their phy score
    }

    cout << sum << endl;

    return 0;
}