/*
https://codebreaker.xyz/problem/foreveralone
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


/*
because I need to find all the subgraphs which contains 1 vertex only, 
so I need to define a map which groups all vertices
key: starting vertex
value: set, which contains all the vertices reachable from the starting vertex
*/
unordered_map<int, unordered_set<int>> groups;

void dfs(int v, int leader) {

    // base case - ignore if it is reachable
    if(visited[v]) {
        return;
    }

    // otherwise, I need to add v to the subgraph led by vertex leader
    groups[leader].insert(v);
    visited[v] = 1;

    for(int x : adjlist[v]) {
        dfs(x, leader);
    }
}


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up


    freopen("1399_dfs_graph_codebreaker_foreveralone.txt", "r", stdin);

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


    // step 3) dfs all vertices, group them into unordered_map
    // loop all starting vertex
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, i); // I need the 2nd para, which is the group leader
        }
    }

    // step 4) loop all the groups, if the set has only 1 vertex, then it is a lonely cat
    int lonely_cat_count = 0;
    for(auto i : groups) {
        if(i.second.size() == 1) {
            lonely_cat_count++;
        }
    }

    cout << lonely_cat_count << endl;

    return 0;
}