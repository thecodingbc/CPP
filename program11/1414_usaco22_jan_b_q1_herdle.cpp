/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1179

------------------
Analysis
------------------

To make thing simpler, we can just use 2 vectors to store all 9 chars

v1: COWSAYMOO
v2: WINTHEIOI

then we can use dual pointers to point to the 2 vectors
we compare the 2 chars

step 1) we compare the 9 pairs one by one
if they are the same, green++, we need to avoid the pair to be added to the 2 maps

step 2) we also need 2 maps which summarize how many times a char appears in v1 or v2. so that we can calculate the count of yellow

map<char, in> mp1;
map<char, in> mp2;

mp1 = {
    'C' : 1,
    'O' : 3,
    'W' : 1
}

mp2 = {
    'O' : 1
}

I can just loop all the pairs of mp1.

*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    freopen("1414_usaco22_jan_b_q1_herdle.txt", "r", stdin);

    // step 1) I define 2 char vector to store the data given by the Q
    vector<char> v1(9);
    vector<char> v2(9);

    for(int i = 0; i < 9; i++) {
        cin >> v1[i];
    }

    for(int i = 0; i < 9; i++) {
        cin >> v2[i];
    }

   /*
    string v1, v2, t;

    for(int i = 0; i < 3; i++) {
        getline(cin, t);
        v1 += t;
    }
    for(int i = 0; i < 3; i++) {
        getline(cin, t);
        v2 += t;
    }
    */

    // LOGGING using cerr, which will be ignore by OJ
    // for(char c : v1) {
    //     cerr << c << " ";
    // }

    // for(char c : v2) {
    //     cerr << c << " ";
    // }

    // step 2) define 2 maps to summarize, how many times each char appear. (We only collect those chars which are not same at the same position)
    map<char, int> mp1;
    map<char, int> mp2;

    // step 3) define a int to same how many chars are the same at the same position
    int sameCount = 0;
    // step 4) define a int to same how many chars are the same but at different position
    int sameCount2 = 0;

    // step 5) calculate sameCount
    // I just need to use 2 pointers compare them in pairs
    for(auto iter1 = begin(v1), iter2 = begin(v2);
             iter1 != end(v1) && iter2 != end(v2);
             iter1++, iter2++) {

        if(*iter1 == *iter2) { // if they are the same green++
            sameCount++;
        }
        else {
            mp1[*iter1]++;
            mp2[*iter2]++;
        }
    }

    // step 6) calculate sameCount2
    for(auto p : mp1) {
        char ch = p.first;
        int countInMp1 = p.second;
        int countInMp2 = mp2[ch];
        sameCount2 += min(countInMp1, countInMp2);
    }

    // step 7) print result
    cout << sameCount << endl;
    cout << sameCount2 << endl;

    return 0;
}