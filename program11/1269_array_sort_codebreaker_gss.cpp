/*
https://codebreaker.xyz/problem/GSS
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1269_array_sort_codebreaker_gss.txt", "r", stdin); // Remove this line before your submit
    
    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<>());

    int sum = 0;

    for(int i = 0; i < n; i++) {

        if(i % 4 == 3) {
            continue;
        }

        sum += arr[i];
    }

    cout << sum << endl;

    return 0;
}