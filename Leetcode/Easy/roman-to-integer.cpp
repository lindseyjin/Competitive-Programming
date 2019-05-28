/*
https://leetcode.com/problems/roman-to-integer/
2019-04-05
*/

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            switch (s.at(i)) {
            case 'I': 
                    if (i != s.length() - 1 && (s.at(i+1) == 'V' || s.at(i+1) == 'X')) num -=1;
                    else num +=1;
                    break;
            case 'V': 
                    num += 5; 
                    break;
            case 'X':
                    if (i != s.length() - 1 && (s.at(i+1) == 'L' || s.at(i+1) == 'C')) num -=10;
                    else num += 10;
                    break;
            case 'L':
                    num += 50; 
                    break;
            case 'C':
                    if (i != s.length() - 1 && (s.at(i+1) == 'D' || s.at(i+1) == 'M')) num -=100;
                    else num += 100; 
                    break;
            case 'D':
                    num += 500; 
                    break;
            case 'M':   
                    num += 1000; 
                    break;
            }

        }
                     
        return num;
    }
};