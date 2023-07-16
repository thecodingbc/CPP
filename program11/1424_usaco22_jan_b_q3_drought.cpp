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
->  2 2 2 4 6 4 -> 2 * 2 = 4
->  2 2 2 2 4 4 -> 2 * 2 = 4
->  2 2 2 2 2 2 -> 2 * 2 = 4 => 16  

    0 1 0
->  0 0 -1


    1 2
->  

    10 9 9
->     

You can lower any adjacent 2 numbers together
Your goal is to make all numbers same

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


// we define total_lowered_cnt as a reference, so that the variable is treated as both input & output
// when you lower the left of v[j], possible you need to lower the left of v[j-1] as well, so this is a recursive function
void lower_left(vector<ll> &v, ll j, ll &total_lowered_cnt) {

    // base case ------------------------
    if(total_lowered_cnt == LLONG_MIN) {
        return;
    }

    if(j <= 0) { // there is no v[j-1]
        return;
    }

    // Now we know, j is a valid index, it has its left

    // task impossible
    if(v[j] < 0) {
        total_lowered_cnt = LLONG_MIN;
        return;
    }

    if(v[j-1] <= v[j]) {
        return;
    }

    if(j == 1) { // v[0] is higher than v[1], task impossible
        total_lowered_cnt = LLONG_MIN;
        return;
    }

    // recursive call -------------------
    ll lower_by = v[j-1] - v[j];
    total_lowered_cnt += lower_by * 2;
    v[j-1] -= lower_by;
    v[j-2] -= lower_by;

    // let's check whether v[j-2] is valid
    if(v[j-2] < 0) {
        total_lowered_cnt = LLONG_MIN;
        return;
    }

    // now v[j-2] can possibly higher than v[j-3]
    lower_left(v, j-2, total_lowered_cnt);
}


// we define total_lowered_cnt as a reference, so that the variable is treated as both input & output
// when you lower the left of v[j], possible you need to lower the left of v[j-1] as well, so this is a recursive function
void lower_right(vector<ll> &v, ll j, ll &total_lowered_cnt) {

    // base case ------------------------
    if(total_lowered_cnt == LLONG_MIN) {
        return;
    }

    if(j >= v.size() - 1) { // there is no v[j+1]
        return;
    }

    // Now we know, j is a valid index, it has its left

    // task impossible
    if(v[j] < 0) {
        total_lowered_cnt = LLONG_MIN;
        return;
    }

    if(v[j+1] <= v[j]) {
        return;
    }

    if(j == v.size() - 2) { // v[v.size() - 1] is higher than v[v.size() - 2], task impossible
        total_lowered_cnt = LLONG_MIN;
        return;
    }

    // recursive call -------------------
    ll lower_by = v[j+1] - v[j];
    total_lowered_cnt += lower_by * 2;
    v[j+1] -= lower_by;
    v[j+2] -= lower_by;

    // let's check whether v[j-2] is valid
    if(v[j+2] < 0) {
        total_lowered_cnt = LLONG_MIN;
        return;
    }

    // now v[j+2] can possibly higher than v[j+3]
    lower_right(v, j+2, total_lowered_cnt);
}




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

        for(ll j = 0; j < size; j++) {
            lower_left(v, j, total_lowered_cnt); // make v[j-1] is same as v[j]
            lower_right(v, j, total_lowered_cnt); // make v[j+1] is same as v[j]
        }

        cout << (total_lowered_cnt == LLONG_MIN ? -1: total_lowered_cnt) << endl;

    }

    return 0;
}