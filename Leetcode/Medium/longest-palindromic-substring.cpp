/*
https://leetcode.com/problems/longest-palindromic-substring/
2019-04-05
*/

class Solution {
public:
    int findLongest(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
            left--;
            right++;
        }  
        
        return right-left-1;
    }
    
    string longestPalindrome(string s) {
        string longest = "";
        int len, left, right;
        
        for (int i = 0; i < s.length(); i++) {
            // check even and odd palindrome
            len = max(findLongest(s, i-1, i), findLongest(s, i-1, i+1));
            if (len > longest.length()) longest = s.substr(i-len/2, len);
        }
        return longest;
    }
};