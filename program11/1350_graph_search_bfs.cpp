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


void bfs(int s) {

    queue<int> q;
    visited[s] = 1;
    cout << s << " ";

    q.push(s);

    while(!q.empty()) {

        int v = q.front();
        q.pop();

        for(auto i : adjlist[v]) {

            // if node i is visited / explored, then we ignore it
            if(visited[i]) {
                continue;
            }

            q.push(i); // because we push new nodes to the back of the queue, the front of the queue would always be an unvisited node of smaller layer(depth)
            visited[i] = 1;
            cout << i << " ";
        }
    }
}





int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    cout << "Breadth first search" << endl;
    bfs(2); // vertex 0 is the starting vertex, the purpose of the function is to find all vertex reachable from 0


    return 0;
}