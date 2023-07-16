/*
https://codebreaker.xyz/problem/splithunny

For graph topic, till now, we've learnt 2 ways to express a graph - adjacent matrix / adjacent list

In both cases, we call them explicit graph.

There is also another kind of graph - we call it implicit graph.

The implicit graph is expressed using a 2d array, sometimes, we just call it grid

Remember adjacent matrix uses a 2d array as well, grid also uses a 2d array.

In adjacent matrix
1) the index of the column and row means the index of the vertices.
2) if it is undirected graph, the adjacent matrix is always symmetric.
3) the value inside the adjacent matrix, means whether an edge exists or not between 2 vertices
4) an vertex can possibly join with any number of other vertices

In grid
1) vertices are cells of the grid
2) we never explicitly express an edge between 2 vertices
3) because, it is standard grid, so a cell inside the grid can only have edge with cells north / south / east / west.
4) sometimes, ne / nw / se / sw 4 more direction.

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int height, width;

char grid[110][110];
bool visited[110][110];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int x, int y) {

    if(visited[x][y]) {
        return;
    }

    visited[x][y] = true;

    for(int k = 0; k < 4; k++) {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 0 || nx >= height || ny < 0 || ny >= width) {
            continue;
        }

        if(!visited[nx][ny] && grid[nx][ny] == 'H') {
            dfs(nx, ny);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1474_graph_codebreaker_splithunny.txt", "r", stdin); // Remove this line before your submit

    cin >> height >> width;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cin >> grid[i][j];
        }
    }

    int sum = 0;

    /*
    In 1394, we use single number to represent the starting vertex
    here, we need to use coordinates(x, y) to represent the starting vertex
    */
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {

            if(visited[i][j] || grid[i][j] == '.') {
                continue;
            }

            // i've found a never visited true vertex
            dfs(i, j);
            sum++;
        }
    }


    cout << "Oh, bother. There are " << sum << " pools of hunny." << endl;

    return 0;
}

/*
Reference: 1394
*/