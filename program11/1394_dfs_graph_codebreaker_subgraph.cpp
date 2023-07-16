/*
https://codebreaker.xyz/problem/subgraphs

--------------
analysis
--------------
we can just use dfs ( which is a simple recursive)
dfs(1) will mark all vertices which are connected to '1', as 'visited'.

so we can :

for v in V {
    if(!visited(v)) {
        count++;
        dfs(v);
    }
}


*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;


/*
1) to make it simple, we can define the graph adjlist as a global variable
2) its max vertices count is 1,000,000
3) so I can define my adjlist size to 1,000,005
*/

vector<int> adjlist[1'000'005];

// no matter it is bfs or dfs, both requires this same-size boolean array
bool visited[1'000'005];


void dfs(int i) {

    // base case
    if(visited[i]) {
        return;
    }

    // typical dfs needs to print the vertex to the console, but here we won't bother
    // cout << i << endl;

    // recursive call
    visited[i] = true;
    for(int x : adjlist[i]) {
        dfs(x);
    }
}


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1394_dfs_graph_codebreaker_subgraph.txt", "r", stdin);

    // step 1) load vertices and edge count from the Q
    int n, e;
    cin >> n >> e;

    // step 2) load graph definition from the Q, node index starts from 0, so i start from 0
    int a, b;

    for(int i = 0; i < e; i++) {
        // as it is bidirectional edges, so I add 2 edges to the graph
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }


    // step 3) I simply dfs all the vertices
    int sub_graph_count = 0;


    for(int i = 0; i < n; i++) { // 1st level, starting vertex

        // if it is not visited, meaning this is a new vertex, or a new subgraph, which is not reachable from any previous vertices
        if(!visited[i]) {
            dfs(i);
            sub_graph_count++;
        }

    }

    cout << sub_graph_count << endl;


    return 0;
}