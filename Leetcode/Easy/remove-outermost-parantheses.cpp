/*
https://leetcode.com/contest/weekly-contest-131/problems/remove-outermost-parentheses/
2019-04-06
*/

class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        int count = 0;
        int left = 0;
        
        // keep track of nested parantheses
        for (int i = 0; i < S.length(); i++) {
            if (S.at(i) == '(') {
                if (count == 0) left = i+1;
                count++;
            } else if (S.at(i) == ')') {
                count--;   
                if (count == 0) ans += S.substr(left, i-left);    
            }
        }
        
        return ans;
    }
};