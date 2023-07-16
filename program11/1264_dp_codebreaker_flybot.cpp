/*
https://codebreaker.xyz/problem/flybot

mod operation:
(a + b) % p = (a % p + b % p) % p 
(a - b) % p = (a % p - b % p ) % p
(a * b) % p = (a % p * b % p) % p 
a ^ b % p   = ((a % p)^b) % p

*/



#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1264_dp_codebreaker_flybot.txt", "r", stdin); // Remove this line before your submit

    // read data from q -----------------

    int row, col;
    cin >> row >> col;

    int arr[row][col];

    string tmp;

    for(int i = 0; i < row; i++) {
        cin >> tmp;
        for(int j = 0; j < col; j++) {
            arr[i][j] = tmp[j] == '.' ? 0 : 1;
        }
    }

    /*
    
    final Q: arr[row][col]
    overlapping subproblems: total solutions to the position on its left and top.

    step 1) find the state the question, define dp array

    there are 2 states in its question.
    row & column
    */
    int dp[row][col];
    memset(dp, 0, sizeof(int) * row * col); // set all to 0


    /*
    meaning of dp[i][j]:
    the total solutions divided by 1000000007
    if the bot walks from [0,0] to [i,j]
    */
   
    /*
    step 2) init the dp array base case
    */
    dp[0][0] = 1;

    
    /*
    step 3) state transition
    dp[i][j] = dp[i-1][j] + dp[i][j-1]
    */

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {

            // base case
            if(i == 0 && j == 0){ // init position
                continue;
            }

            // corner case
            if(arr[i][j] == 1) { //it is a wall
                dp[i][j] == 0;
                continue;
            }

            // state transtion
            if(i > 0) {
                dp[i][j] += dp[i-1][j];
            }
            if(j > 0) {
                dp[i][j] += dp[i][j-1];
            }

            // mod operation
            dp[i][j] %= 1000000007;
        }
    }

    cout << dp[row-1][col-1] << endl;

    return 0;
}