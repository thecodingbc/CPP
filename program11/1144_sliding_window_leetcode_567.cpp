/*
https://leetcode.com/problems/permutation-in-string/
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> needs, window;
        for(char ch : s1){
            needs[ch]++;
        }

        int left =0, right = 0;
        int good_ch_count = 0;

        while(right < s2.size()) {

            char ch = s2[right];
            right++;

            if(needs.count(ch)) {
                window[ch]++;
                if(window[ch] == needs[ch]) {
                    goo_ch_count++;
                }
            }

            while(good_ch_count == needs.size()) {
                
                if(right - left == s1.size()) {
                    return true;
                }

                ch = s2[left];
                left++;

                if(needs.count(ch)) {
                    if(window[ch] == needs[ch]) {
                        good_ch_count--;
                    }
                    window[ch]--;
                }
            }
        }
        return false;
    }
};