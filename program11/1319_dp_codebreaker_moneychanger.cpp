/*
https://codebreaker.xyz/problem/moneychanger
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1319_dp_codebreaker_moneychanger.txt", "r", stdin); // Remove this line before your submit

    int n, v;
    cin >> n >> v; // total n coins, give away amount: v cents

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    /*
    step 1) ----------------
    define dp array
    dp[i] means: 
    for i cents, the min coins count required
    I make size to v+1
    */
    int dp[v+1];
    for(int i = 0; i <= v; i++) {
        dp[i] = INT_MAX; // means impossible
    }

    /*
    step 2) ----------------
    base case
    if you need to give away 0 cents, then you need 0 coins.
    */
    dp[0] = 0;

    /*
    step 3) ---------------------
    state transtion. 
    
    If I need to give away i cents in total
    and my coins denomination is 1c, 2c, 3c 

    then dp[i] = min(dp[i-1], dp[i-2], dp[i-3]) + 1
    */

    for(int i = 1; i <= v; i++) {

        // let me loop all coins denomination
        for(int d : arr) {
            if(d > i) { // ignore if coin denomination is too big for amount i
                continue;
            }
            if(dp[i-d] == INT_MAX) { // ignore no solution situation
                continue;
            }
            dp[i] = min(dp[i], dp[i-d] + 1);
        }
    }

    cout << (dp[v] == INT_MAX ? -1 : dp[v]) << endl;

    return 0;
}