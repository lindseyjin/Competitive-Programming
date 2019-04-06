/*
https://leetcode.com/problems/integer-to-roman/
2019-04-05
*/

// Concise Solution
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        map <int, string, greater<int>> m {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
            {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} 
        };
        
        for (auto it = m.begin(); it != m.end(); it++) {
            while (num >= it->first) {
                num -= it->first;
                ans += it->second;
            }     
        }

        return ans;
    }
};

// Better runtime/memory solution but it looks disgusting
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        while (num >= 1000) {
            ans += 'M';
            num -= 1000;
        } 
        if (num >= 900) {
            ans += "CM";
            num -=900;
        }
        if (num >= 500) {
            ans += 'D';
            num -=500;
        }
        if (num >= 400) {
            ans += "CD";
            num -=400;
        }
        while (num >= 100) {
            ans += 'C';
            num -= 100;
        } 
        if (num >= 90) {
            ans += "XC";
            num -=90;
        }
        if (num >= 50) {
            ans += 'L';
            num -=50;
        }
        if (num >= 40) {
            ans += "XL";
            num -=40;
        }
        while (num >= 10) {
            ans += 'X';
            num -= 10;
        } 
        if (num >= 9) {
            ans += "IX";
            num -=9;
        }
        if (num >= 5) {
            ans += 'V';
            num -=5;
        }
        if (num >= 4) {
            ans += "IV";
            num -=4;
        }
        while (num >= 1) {
            ans += 'I';
            num -=1;
        }
        
        return ans;
    }
};
