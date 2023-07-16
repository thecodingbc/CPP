/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1180

Analysis:
In total 10^4 possibilities, brute force
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
this function check which die win, x or y.
it return 1 if x wins
it return -1 if y wins
it return 0 if it ties.
*/
int check_win(vector<int> x, vector<int> y) {
    int x_win_count = 0;
    int y_win_count = 0;

    for(int a : x) {
        for(int b : y) {
            if(a > b) {
                x_win_count++;
            }
            else if(a < b) {
                y_win_count++;
            }
        }
    }

    if(x_win_count > y_win_count) {
        return 1;
    }
    
    if(x_win_count < y_win_count) {
        return -1;
    }
    return 0;
}


// return a boolean to tell, whether such a die exists so that they are non-transitive
bool find_die(vector<int> loser, vector<int> winner) {

    for(int a = 1; a <= 10; a++) {
        for(int b = 1; b <= 10; b++) {
            for(int c = 1; c <= 10; c++) {
                for(int d = 1; d <= 10; d++) {
                    
                        vector<int> my_die = {a, b, c, d};

                        int my_die_win = check_win(my_die, loser);

                        if(my_die_win != -1) { //if loser doesn't win, continue
                            continue;
                        }

                        my_die_win = check_win(my_die, winner);
                        if(my_die_win != 1) { // if winner doesn't lose, continue
                            continue;
                        }                       

                        return true; // find it!
                }
            }
        }
    }

    return false; // doesn't exist!
}

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1419_usaco22_jan_b_q2_non_transitive_dice.txt", "r", stdin);

    int n;
    cin >> n;

    for(int z = 0; z < n; z++) {

        // step 1) read all data in
        vector<int> x(4);
        vector<int> y(4);

        for(int i = 0; i < 4; i++) {
            cin >> x[i];
        }

        for(int i = 0; i < 4; i++) {
            cin >> y[i];
        }

        // step 2)check whether x win or y win, I write a new function for this
        int x_win = check_win(x, y);

        if(x_win == 0) { // if tie, return no
            cout << "no" << endl;
        }
        else {
            bool new_die_found = false;

            if(x_win == 1) {
                new_die_found = find_die(y, x);
            }
            else {
                new_die_found = find_die(x, y);
            }

            if(new_die_found) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}