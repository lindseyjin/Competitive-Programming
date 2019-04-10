/*
https://leetcode.com/problems/string-to-integer-atoi
2019-04-09
*/

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        bool neg = false;
        int num = 0;
        
        // trim leading whitespace
        while (index < str.length() && str.at(index) == ' ') index++;
        if (index == str.length()) return num;
        
        // optional +/-
        if (str.at(index) == '+') {
            index++;
        } else if (str.at(index) == '-') {
            neg = true;
            index++;
        }  

        // parse number
        while(index < str.length()) {
            if (str.at(index) < '0' || str.at(index) > '9') return neg == true ? -1*num : num;
            if (neg && num > ((INT_MAX - (str.at(index) - '0'))/10)) return INT_MIN;
            if (!neg && num > ((INT_MAX - (str.at(index) - '0'))/10)) return INT_MAX;
            num *=10;
            num +=str.at(index) - '0';
            index++;
        }
        
        return neg == true ? -1*num : num;
    }
};