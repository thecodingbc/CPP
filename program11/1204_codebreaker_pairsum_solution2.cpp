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

    ll odd_count = 0LL, even_count = 0LL;

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0) {
            even_count++;
        }
        else {
            odd_count++;
        }
    }

    ll result = even_count * odd_count;

    cout << result << endl;
    return 0;
}

/*

    Please read:
    https://www.wikihow.com/Calculate-Permutations

    5P5 = 5! = 5 * 4 * 3 * 2 * 1
    2P5 = 5!/(5-2)! = 5 * 4



*/