/*
https://codebreaker.xyz/problem/catfight

1st line: N & P
2nd line: N integers

Requirement: find max continuous numbers, their sum is less than P


*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1214_sliding_window_codebreaker_catfight.txt", "r", stdin); // Remove this line before your submit

    ll n, p;
    cin >> n >> p;

    ll arr[n];
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll left = 0LL, right = 0LL;

    ll max_length = 0LL, sum = 0LL;

    while(right < n) {

        sum += arr[right];
        right++;

        if(sum < p && right - left > max_length) {
            max_length = right - left;
        }

        while(sum >= p) {
            sum -= arr[left];
            left++;
        }
    }
    
    cout << max_length << endl;

    return 0;
}