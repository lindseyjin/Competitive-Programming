/**
https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps
2019-11-24
**/

class Solution {
public:
    int arrLen;
    long MOD = 1e9+7;
    unordered_map<int, unordered_map<int, long>> memo;
    long dp(int steps, int i) {
        if (steps == 0) {
            return (i == 0) ? 1 : 0;
        }
        if (i < 0 || i >= arrLen || i > steps) return 0;
        if (memo.count(steps) && memo[steps].count(i)) return memo[steps][i];
        
        long l = dp(steps-1, i-1);
        long r = dp(steps-1, i+1);
        long s = dp(steps-1, i);
                
        return memo[steps][i] = (l+r+s)%MOD;
    }
    
    int numWays(int steps, int arrLen) {
        this->arrLen = arrLen;
        return dp(steps, 0);
    }
};