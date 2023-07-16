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

        /*
        If I plant grass G at index x, then all cow G have grass to eat before x + k
        I can ignore all G cow until index x + k + 1
        */
        int g_ignore = -1; // to store all cows G have grass to eat on the left of index g_ignore
        int h_ignore = -1; // to store all cows H have grass to eat on the left of index h_ignore


        // step 3) loop all chars(cow) in s
        for(int i = 0; i < n; i++) {

            if(s[i] == 'G' && i <= g_ignore) {
                continue;
            }

            if(s[i] == 'H' && i <= h_ignore) {
                continue;
            }

            /*
            if code goes here, I know the cow has no grass to eat.
            And I want to plant the grass as far as possible, so that the grass can potentially cover more cows
            */

            // plant grass
            int place_to_plant = min(i + k, n - 1);
                        
            if(res[place_to_plant] != '.') {
                place_to_plant--;
            }

            res[place_to_plant] = s[i];

            // update the variables
            patchCount++;
            if(s[i] == 'G') {
                g_ignore = place_to_plant + k;
            }
            if(s[i] == 'H') {
                h_ignore = place_to_plant + k;
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