/*
https://codebreaker.xyz/problem/stepgame
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1329_dp_codebreaker_stepgame.txt", "r", stdin); // Remove this line before your submit

    // step 1) read in all data from the question

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // step 2) prepare dp array
    // dp[i] means: the min sum when the subarray ends at arr[i]
    int dp[n];

    // step 3) init dp array
    dp[0] = arr[0];

    // step 4) state transition
    for(int i = 1; i < n; i++) {
        if(dp[i-1] < 0) {
            dp[i] = dp[i-1] + arr[i];
        }
        else {
            dp[i] = arr[i];
        }
    }

    // step 5) output result
    cout << *min_element(dp, dp + n) << endl;    

    return 0;
}