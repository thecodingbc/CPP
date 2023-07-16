#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
map / multimap
set / multiset
priority_queue
*/

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    // multiset<int> ms1; // small to big
    multiset<int, greater<int>> ms1; // big to small

    ms1.insert(4);
    ms1.insert(3);
    ms1.insert(6);
    ms1.insert(2);
    ms1.insert(5);
    ms1.insert(5);
    ms1.insert(1);

    for(auto i : ms1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "multiset head is: " << *begin(ms1) << endl;

    //remove head, pass in an iterator
    ms1.erase(begin(ms1));

    cout << "After remove multiset head, its size now is: " << ms1.size() << endl;

    for(auto i : ms1) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}