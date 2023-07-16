#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Requirement:

given an array of integers arr
there is a sliding window of size k which is moving from left to right
You can only see the 4 numbers in the window.

Return the min number in each sliding window
*/

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    int arr[] = {2, 1, 4, 5, 3, 4, 1, 2};
    int k = 4; // window size is 4
    int arr_size = sizeof(arr) / sizeof(arr[0]);


    /*
    
    1) we define a strictly increasing deque 
    2) 1st value is always the smallest number inside the window

    step 1) enqueue 2, which is the smallest of the window, right now   [2]
    step 2) enqueue 1, 1 is smaller than 2, 1 is after 2 => I will dequeue 2 first, before I enqueue 1. [1]
    step 3) enqueue 4   [1, 4]
    step 4）enqueue 5   [1, 4, 5]
    step 5) enqueue 3, 3 is smaller than 4 & 5, 3 is after 4 & 5,  => I dequeue 4 & 5 first before I enqueue 3   [1, 3]
    
    */

    deque<pair<int, int>> window;

    for(int i = 0; i < arr_size; i++) {

        // step 1) add value to dequeue 
        while(!window.emtpy() && window.back().first >= arr[i]) {
            window.pop_back();
        }

        window.push_back(make_pair(arr[i], i));

        // step 2) check window head
        while(window.front().second <= i - k) {
            window.pop_front();
        }

        // find result
        if(i >= k -1) {
            cout << (window.front().first) << endl;
        }
    }
    return 0;
}