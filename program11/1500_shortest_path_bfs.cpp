/*

Q description:

You are given
1) an unweighted graph
2) a starting vertex

You are asked to calcuate the shortest distance to all other vertices from this starting vertex.

--------------------
Analysis
--------------------
1) BFS is best suited to calculate the distance to all other vertices given a starting vertex
2) As BFS groups all the vertices into layers based on their distance to the starting vertex.
3) As BFS visits all other vertices from near to far
4) All we need is to add an int array, to remember all the distances to all the vertices.
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adjlist[6] = {
    {1, 2},
    {0, 3},
    {0, 3, 4},
    {1, 2, 4, 5},
    {2, 3, 5},
    {3, 4}
};

bool visited[6];

int dist[6];

void init_dist() {
    for(int& i : dist) {
        i = INT_MAX;
    }
}

void bfs(int s) {

    queue<int> q;

    visited[s] = 1;

    q.push(s);

    while(!q.empty()) {

        int v = q.front();
        q.pop();

        for(auto i : adjlist[v]) {
            
            if(visited[i]) {
                continue;
            }

            visited[i] = 1;
            q.push(i);

            dist[i] = dist[v] + 1;
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    cout << "Using BFS to calculate the distance from vertex 0 to all other vertices: " << endl;

    init_dist();

    dist[0] = 0;

    bfs(0);

    cout << endl;

    for(int i = 0; i < 6; i++) {
        cout << "distance from vertex 0 to vertex " << i << " is : " << dist[i] << endl;
    }

    return 0;
}