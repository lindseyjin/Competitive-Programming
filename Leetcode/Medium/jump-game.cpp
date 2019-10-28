/*
https://leetcode.com/problems/jump-game/
2019-10-27
*/
class Solution {
public:
    /*
    Attempt 1: Dp with backtracking: Time limit exceeded
    bool dp(int i, vector<int>& nums, vector<bool>& memo) {
        if (i > nums.size()-1 || !memo[i]) return false;
        if (i == nums.size()-1) return true;
        
        // try largest -> smallest jump
        int j = i + nums[i] >= nums.size() ? nums.size()-1 : i + nums[i];
        while(j > i) {
            if (dp(j, nums, memo)) return true;
            j--;
        }
        
        memo[i] = false;
        return false;
    }
    */
    
    /*
    Attempt 2: Dp with optimized backtracking: memo table with 3 states and one initial iteration of setting "good values"
    bool dp(int i, vector<int>&nums, vector<int>&memo) {
        if (memo[i] == 0) return false;
        if (memo[i] == 1) return true;
        
        int j = i + nums[i];
        if (j >= nums.size()-1) return true;
        while (j > i) {
            if (dp(j, nums, memo)) return true;
            j--;
        }
        
        memo[i] = 0;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        // 0 = false
        // 1 = true
        // 2 = unknown
        
        if (nums.size() == 0) return false;
        vector<int> memo(nums.size(), 2);
        
        // find all obviously true indices
        for (int i = 0; i < nums.size(); ++i) {
            if (i + nums[i] >= nums.size()-1) memo[i] = 1;
        }
        
        return dp(0, nums, memo);
    }
    */
    
    bool canJump(vector<int>& nums) {
        // bottom-up approach
        // keep track of farthest element we need to reach to get to the end
        int farthest = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= farthest) {
                farthest = i; // change farthest to current index
            }
        }
        
        return farthest == 0 ? true : false;
    }
    
};