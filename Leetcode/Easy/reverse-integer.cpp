/*
https://leetcode.com/problems/reverse-integer
2019-04-09
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            // check for overflow
            if ((x < 0 && ans < (INT_MIN - x%10)/10) || (x > 0 && ans > (INT_MAX - x%10)/10)) return 0;
            ans *= 10;
            ans += x%10;
            x /=10;
        }
        
        return ans;
        
    }
};