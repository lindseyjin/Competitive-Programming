/*
https://leetcode.com/problems/permutation-in-string
2020-06-08
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1 == s2) return true;
        if (s1.length() > s2.length()) return false;
            
        // use vector of numbers instead of map to optimize
        int letters[26] = {0};
        int offset = s1.length();     
            
        for (int i = 0; i < s1.length(); i++) {
            letters[s1[i]-'a']++;
        }
            
        // construct a sliding window
        int window[26] = {0};
        for (int i = 0; i < s2.size(); i++) {
            int curr = s2[i]-'a';
            window[curr]++;
            offset = (window[curr] <= letters[curr])? offset - 1 : offset + 1;
            
            if (i >= s1.length()) {
                int last = s2[i - s1.length()] - 'a';
                window[last]--;
                offset = (window[last] < letters[last]) ? offset + 1: offset - 1;
            }
            
            if (offset == 0) return true;
        }
        
        return false;
    }
};