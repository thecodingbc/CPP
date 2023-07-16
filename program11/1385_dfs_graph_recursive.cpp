#include <bits/stdc++.h>
#define ll long long
using namespace std;


/*
graph 1: directed
input: n = 4, e = 6
0 -> 1, 0 -> 2,
1 -> 2, 1 -> 3,
2 -> 0,
3 -> 3

vector<int> adjlist[4] = {
    {1, 2},
    {2, 3},
    {0},
    {3}
};

bool visited[4];

*/


/*
graph 2: undirected

n = 6, e = 8

0 - 1, 0 - 2
1 - 0, 1 - 3
2 - 0, 2 - 3, 2 - 4
3 - 1, 3 - 2, 3 - 4, 3 - 5
4 - 2, 4 - 3, 4 - 5
5 - 3, 5 - 4

*/

vector<int> adjlist[6] = {
    {1, 2},
    {0, 3},
    {0, 3, 4},
    {1, 2, 4, 5},
    {2, 3, 5},
    {3, 4}
};

bool visited[6];


void dfs(int s) {

    // base case ------------------------------

    // if the node is already visited, return
    if(visited[s]) {
        return;
    }

    // this is a new node, I will visit it
    visited[s] = 1;
    cout << s << " ";

    // recursive call -------------------------

    // as soon as I've visited the node s, then I am going to visit all its neighbours.
    for(auto i : adjlist[s]) {
        dfs(i);
    }

}


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    cout << "Depth First Search " << endl;
    dfs(2);

    return 0;
}