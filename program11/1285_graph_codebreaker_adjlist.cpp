/*
https://codebreaker.xyz/problem/adjlist
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1285_graph_codebreaker_adjlist.txt", "r", stdin); // Remove this line before your submit

    int n, e;

    cin >> n >> e;

    // init
    // vector<vector<int>> adjlist(n); // create a 2-d nested vector adjlist which contains n empty vectors
    vector<int> adjlist[n+1]; // create a 2-d nested vector adjlist which contains n empty vectors, keep 0 unused

    // fill up
    int a, b;
    for(int i = 0; i < e; i++) {
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    // output
    for(int i = 1; i <= n; i++) { // keep 0 unused
        vector<int> v = adjlist[i];
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}