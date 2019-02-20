/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different 
substrings even they consist of same characters.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.length();
        if (ans == 1) return ans;

        for (int i = 1; i < s.length(); i++) {

            // even palindrome
            for (int x = 1; x <= i && x <= s.length() - i; x++) {
                if (s.at(i - x) == s.at(i - 1 + x)) ans++;
                else break;
            }
            // odd palindrome, different middle character
            for (int x = 1; x <= i && x < s.length() - i; x++) {
                if (s.at(i - x) == s.at(i + x)) ans++;
                else break;
            }
        }

        return ans;
    }
};