/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
2019-04-05
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, repeated;
        string curr = "";
        
        for (int x = 0; x < s.length(); x++) {
            repeated = curr.find(s.at(x));
            if (repeated != -1) {
                if (curr.length() > longest) longest = curr.length();
                curr = curr.substr(repeated + 1, curr.length() - repeated - 1); 
            }
            curr += s.at(x);
        }

        if (curr.length() > longest) longest = curr.length();
        return longest;
    }
};