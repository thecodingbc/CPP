/*
https://codebreaker.xyz/problem/adjmatrix
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up
    freopen("1280_graph_codebreaker_adjmatrix.txt", "r", stdin); // Remove this line before your submit

    int n, e;
    cin >> n >> e;

    int arr[n][n];


    // init
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    // create edge
    int a, b;
    for(int i = 0; i < e; i++) {
        cin >> a >> b;
        arr[a-1][b-1] = 1; // as the edges given are 1 based.
        arr[b-1][a-1] = 1;
    }

    // output
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
