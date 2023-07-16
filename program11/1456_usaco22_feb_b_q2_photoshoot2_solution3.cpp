/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1204

Q Description:
1st line: number N
2nd line: N numbers original state
3rd line: N numbers target state

Requirement:
One modification is to move any number some positions to its left
Count the minimum number of modification.

Example:

5
5 1 3 2 4
4 5 2 1 3

Answer is 2

-----------------
analysis
-----------------

if there are in total 5 numbers, then we max we move count is 4.
we just need to check them 1 by 1, whether each one of them needs to be moved or not.

Let's consider nmber 4 & 5.
In original, 4 is after 5, but
in target,   4 is before 5.

Conclusion 1: 4 has to be moved to the front of 5.
Conclusion 2: we just need to find any pair for each number in original, which satisfies the above case, then we know it needs to be moved.

For 5, there is no number on its left, so 5 doesn't require movement.

For 1,                   1 index in target is 3
       5 is on its left, 5 index in target is 1, 5 is on the left of 1 as well in target, so 1 doesn't require movement.

For 3,                   3 index in target is 4
       5 is on its left, 5 index in target is 1, 5 is on the left of 3 as well in target
       1 is on its left, 1 index in target is 3, 3 is on the left of 1 as well in target, so 3 doesn't require movement.

For 2,                   2 index in target is 2
       5 is on its left, 5 index in target is 1, 5 is on the left of 2 as well in target
       1 is on its left, 1 index in target is 3, 1 is on the RIGHT of 2! So 2 requires movement.

For 4,                   4 index in target is 0
       5 is on its left, 5 index in target is 1, 5 is on the RIGHT of 4! So 4 requires movement.

Attention:
The most important data structure is the number position in target list.       


*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1454_usaco22_feb_b_q2_photoshoot2.txt", "r", stdin);

    // step 1) load data in ------------------------------

    int n;
    cin >> n;

    vector<int> original(n);
    vector<int> target(n);

    for(int &i : original) cin >> i;
    for(int &i : target) cin >> i;

    // step 2) find all numbers' position in target list ---------------
    unordered_map<int, int> positions;
    /*
    离散化 -> convert the orignal list to its sequence / orders.
    */

    for(int i = 0; i < n; i++) {
        // the number target[i]'s position is i
        positions[target[i]] = i;
    }

    // step 3) 
    int count = 0;

    int maxPos = -1; // this variable means the max position number among the number of no_i's left

    // step 4) loop numbers in original one by one
    for(int i = 0; i < n; i++) {

        // let's check number original[i]
        int no_i = original[i];

        // its position in target is
        int no_i_position = positions[no_i];

        if(no_i_position < maxPos) {
            conut++;
        }

        maxPos = max(maxPos, no_i_position);
    }
    
    cout << count << endl;

    return 0;
}