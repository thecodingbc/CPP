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

    // step 0) create an empty stack
    stack<int> st;

    // step 1) init the stack with starting vertex s
    st.push(s);
    cout << "LOG - push(" << s << ")\n";

    // step 2) repeat until stack is empty
    while(!st.empty()) {

        // step 2.1) pop stack, assign it to variable v
        int v = st.top();
        st.pop();
        cout << "LOG - pop(" << v << ")\n";

        // step 2.2) if v is not visited
        if(!visited[v]) {

            // step 2.2.1) visit v
            cout << "VISIT : " << v << "\n";

            // step 2.2.2) mark it as visisted
            visited[v] = 1;

            // step 2.2.3)
            for(int x : adjlist[v]) {
                st.push(x);
                cout << "LOG - push(" << x << ")\n";
            }
        }
        else {
            cout << "LOG - ignore " << v << ", as it is already visited\n";
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    cout << "Depth First Search " << endl;
    dfs(2);


    return 0;
}