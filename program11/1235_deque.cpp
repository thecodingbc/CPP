#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    deque<int> deq;

    deq.push_back(1); // push to the back of queue          1
    deq.push_back(10); // push to the back of queue         1, 10

    cout << "deque last value is: " << deq.back() << endl;       //   10
    cout << "deque first value is: " << deq.front() << endl;      //  1


    deq.pop_back();   // pop the back most element          1
    deq.push_front(2);                                    //  2, 1
    deq.pop_front();                                      //  1

    cout << deq.size() << endl; 

    cout << deq[0] << endl;

    for(int x : deq) {
        cout << x << endl;
    }


    return 0;
}