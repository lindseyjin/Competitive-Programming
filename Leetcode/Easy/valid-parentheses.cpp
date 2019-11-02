/*
https://leetcode.com/problems/valid-parentheses
2019-11-02
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        char top;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                p.push(s[i]);
            } else {
                if (p.empty()) return false;
                
                top = p.top();
                if (s[i] == ')' && top == '(' || s[i] == '}' && top == '{' || s[i] == ']' && top == '[') {
                    p.pop();
                } else {
                    return false;
                }
            }
        }
        
        if (p.empty()) return true;
        return false;
    }
};