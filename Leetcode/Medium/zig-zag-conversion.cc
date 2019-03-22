/*
https://leetcode.com/problems/zigzag-conversion/
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        bool down = true;
        int rowNumber = 0;
        string rows[numRows]; 
        
        for (int i = 0; i < s.length(); i++) { 
            rows[rowNumber] += s.at(i);
             
            if (down) {
                rowNumber++;
                if (rowNumber >= numRows-1) down = false;
            }
            else {
                rowNumber--;
                if (rowNumber <= 0) down = true;
            }
        }
        
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }
        
        return ans;
    }
};