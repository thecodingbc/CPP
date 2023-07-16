/*
https://leetcode.com/problems/remove-element/
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Analysis:
1) We use dual pointer algo
2) the fast pointer points to the value to be inserted
3) the slow pointer points to the place where the value should be inserted.
4) we let the faster pointer to iterate all numbers inside the vector
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i = 0, j = 0;

        for(;j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }

        nums.resize(i);
        return i;
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