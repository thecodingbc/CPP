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

Move 4 to index 0 -> 4 5 1 3 2
Move 2 to index 2 -> 4 5 2 1 3

Answer is 2

-----------------
analysis
-----------------

1) I need to store the 2 numbers sequence to a vector / array / list
2) because I need to do a lot of delete / insert in original list, so I should choose list, which is very efficient for insert / delete
3) I can use dual pointers algo, which points to both original & target sequence, move them from left to right, calculate the total modifications.
4) I also need the 3rd pointer which helps to find the correct number to be inserted.


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

    list<int> original(n);
    list<int> target(n);

    for(int &i : original) cin >> i;
    for(int &i : target) cin >> i;

    /*
    only works for array & vector
    for(int i = 0; i < n; i++) {
        cin >> original[i];
    }
    */

    // step 2) define 2 pointers to point to the beginning of 2 lists
    auto iter1 = begin(original);
    auto iter2 = begin(target);

    // step 3) define variable of total moves
    int result = 0;
    
    // step 4) move 2 pointers together

    for(;iter1 != end(original) && iter2 != end(target);) { // here max, you loop N

        // base case: if the 2 pointers point to the same number, move both to the right
        if(*iter1 == *iter2) {
            iter1++;
            iter2++;
            continue;
        }

        // if they point to different numbers, then I need to find the number in original list, and move it to iter1

        /*
        define the 3rd pointer in original
        make it equals to iter1
        search from iter1 to the end of original list
        look for the number which is pointed by iter2 in target list

        because original & target are just 2 different combinations of the same numbers
        so I know, definitely, I can find the number
        */

        auto iter3 = iter1;

        while(*iter3 != *iter2) { // N
            iter3++;
        }
        
        // we've found the number

        original.insert(iter1, *iter3); // the number is inserted on the LEFT of pointer iter1, so you don't need to do anything to iter1
        original.erase(iter3);

        // move iter2 1 step
        iter2++;

        result++;
    }

    cout << result << endl;

    return 0;
}

/*
o(N^2)

10^10 -> 10^8, -> 100s
*/