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

we define 2 pointers p & q

5 1 3 2 4
|
p

4 5 2 1 3
|
q

we basically, check numbers in target one by one.
all numbers before q are checked.
all numbers after q are unchecked.

we let pointer p ALWAYS points to an unchecked number, which is AFTER pointer q in target.
this means:
original[p] is ALWAYS after target[q] in target list.

Let's begin:

Have you noticed that 5 is after 4 in target list? 

because original[p] != target[q], so 4 has to be moved to the front, cnt++, 4 is checked.
let's move q, q++


5 1 3 2 4
|
p

4 5 2 1 3
  |
  q

because original[p] == target[q], so 5 doesn't require movement, 5 is checked.
let's move p, p++, move q, q++



Have you noticed that, 1 is after 2 in target list? 

5 1 3 2 4
  |
  p

4 5 2 1 3
    |
    q

because original[p] != target[q], so 2 has to be moved to the front, cnt++, 2 is checked.
let's move q, q++


5 1 3 2 4
  |
  p

4 5 2 1 3
      |
      q

because original[p] == target[q], so 1 doesn't require movement, 1 is checked
p++, q++


5 1 3 2 4
    |
    p

4 5 2 1 3
        |
        q


because original[p] == target[q], so 1 doesn't require movement, 3 is checked
q reaches the end, program finishes.

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 10;

int n;
int original[N], target[N];
bool checked[N];

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1454_usaco22_feb_b_q2_photoshoot2.txt", "r", stdin);

    // step 1) load all data in
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> original[i];
    for(int i = 1; i <= n; i++) cin >> target[i];

    // step 2) I define 2 pointers q & p, p points to original, q points to target
    int p = 1, q = 1;

    // this var save the total count I need to move my cow
    int cnt = 0;

    // then I check all cows in TARGET  list one by one
    // I check each one of them, whether I should move the cow to the front

    for(; q <=n; q++) {

        // if original[p] is checked, move to the next unchecked number.
        // remember: checked numbers are in front of q
        // unchecked numbers are after q

        while(p <=n && checked[original[p]]) p++;

        //if they are different, meaning the orignal[p] is after target[q] in target list
        // target[q] should be moved forwrad, hence cnt++
        if(original[p] != target[q]) cnt++;

        // now target[q] is checked, which is in front of pointer q
        checked[target[q]] = 1;

    }

    cout << cnt << endl;

    return 0;
}