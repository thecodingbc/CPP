/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1252
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;


/*

Brute Force + Greedy

Each cow can move max k steps, so I just check all its reachable spots from -k to +k (brute force)
Each time when I try to plant a grass, I try to plant as far as I can, so that the grass can cover as many cow as it can. (greedy)

*/

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1364_usaco22_b_feeding_the_cow.txt", "r", stdin);

    int t, n, k;
    cin >> t;

    string s; // cows string

    for(int i = 0; i < t; i++) {

        cin >> n >> k;
        cin >> s;

        // step 1) create the result char array, with size = n + 1
        // withe last one using '\0', this is very important when you convert char array to string
        char res[n + 1];
        int patchCount = 0;

        // step 2) initialize all to '.'
        for(int i = 0; i < n; i++) {
            res[i] = '.';
        }
        res[n] = '\0';

        // step 3) loop all chars(cow) in s
        for(int i = 0; i < n; i++) {

            /*
            step 3.1) for each char s[i], we can just check from res[i - k] to res[i + k]
            if I can find any char equals to s[i], then it means the cow at s[i] has grass to eat
            if I cannot find, then I need to plant a grass among res[i - k] to res[i + k]
            of course, I try to plant it as late as possible

            attention:
            1）the index can be invalid, for example if k = 5, 0 - 5 = -5, which is invalid
            2) some position can be taken already, so I need to remember the best position to plant it
            */

            int place = 0;
            bool hasGrass = false;

            for(int j = i - k; j <= i + k; j++) {
                if(j < 0) { // beyond the left boundary
                    continue;
                }
                if(j > n - 1) { //beyond the right boundary
                    break;
                }

                if(res[j] == s[i]) { // res[j] is the grass, s[i] is the cow,if they equal, meaning the cow s[i] has grass to eat
                    hasGrass = true;
                    break;
                }
                else if (res[j] == '.') { // available to plant the grass
                    place = j;
                }
            }

            if(!hasGrass) { // no grass to eat, let's plant the grass at position res[place]
                res[place] = s[i];
                patchCount++;
            }
        }

        // step 4) convert char array to string, print to console
        cout << patchCount << endl;
        string resStr(res);
        cout << resStr << endl;
    }

    return 0;
}

/*

O(n * k)
since both n * k are 10^5, O(10^10)
Your computer runs 10^8 per second
each test case requres 100s

*/