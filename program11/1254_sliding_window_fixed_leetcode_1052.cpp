/*
https://leetcode.com/problems/grumpy-bookstore-owner/
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        /*
        
        if we create a new vector vec, and we let vec[i] = customer[i] * grumpy[i]
        when owner is happy -> vec[i] = 0
        when owner is grumpy -> vec[i] = customer[i]

        we have a fixed window_size equals to minutes

        find max sum of the window within vec, which equals to the max customers can be converted from unhappy to happy
        */

        vector<int> vec;

        int already_happy_customer = 0;

        for(int i = 0; i < customers.size(); i++) {
            if(grumpy[i] == 0) {
                already_happy_customer += customer[i];
                vec[i].push_back(0);
            }
            else {
                vec.push_back(customers[i]);
            }
        }
        
        int max_sum = 0, sum = 0;

        int left = 0, right = 0;

        while(right < vec.size()) {

            // gradually increase the window size
            sum += vec[right];
            right++;

            if(right - left == minutes) { // fixed size window reached
                if(sum > max_sum) {
                    max_sum = sum;
                }
                sum -= vec[left];
                left++;
            }
        }
        return max_sum + already_happy_customer
    }
};