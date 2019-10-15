/*
https://leetcode.com/problems/climbing-stairs/
2019-10-14
*/

class Solution {
public:
    int dp(unordered_map<int, int> &steps, int n) {
        if (n < 0) return 0;
        if (n == 0 || n == 1) return 1;
        if (!steps.count(n)) steps.insert({n, dp(steps, n-1) + dp(steps, n-2)});
        
        return steps.at(n);
    }
    
    int climbStairs(int n) {
        unordered_map<int, int> steps;
        return dp(steps, n);
    }
};