/*
https://leetcode.com/problems/remove-element/
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Analysis:
1) I use single iterator 
2) I loop the iterator from begin(nums) to end(nums)
3) if *iter == val, nums.erase(iter)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        auto iter1 = begin(nums);
        int size = 0;
        
        while(iter1 != end(nums)) {

            if(*iter1 != val) {
                size++;
                iter1++;
            }
            else {
                nums.erase(iter1); // once you erase a number pointed by the iterator, the iterator automatically moves to the next
            }
        }
        return size;
    }
};


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    Solution s;

    vector<int> v = {3, 2, 2, 3};

    int ans = s.removeElement(v, 3);

    cout << ans << endl;

    for(int i : v) {
        cout << i << " ";
    }

    return 0;
}