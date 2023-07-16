/*
https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int left =0, right = 0;
        /*
        [left, right) 
        window size = right - left
        */

        int sum = 0, avg = 0, result = 0;

        while(right < arr.size()) {

            // right pointer value in
            sum += arr[right];
            right++;


            // check window
            if(right - left == k) {

                avg = sum / k;

                if(avg >= threshold) {
                    result++;
                }

                // left pointer value out
                sum -= arr[left];
                left++;
            }
        }

        return result;

    }
};