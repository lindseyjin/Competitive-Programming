/*
https://leetcode.com/problems/search-insert-position/
2019-04-09
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        if (target < nums.at(0)) return 0;
        if (target > nums.at(nums.size() - 1)) return nums.size();
            
        while (left < right) {
            int index = (right - left)/2 + left;
            if (nums.at(index) == target) return index;
            else if (nums.at(index) < target) left = index + 1;
            else right = index;
        }
        
        return left;
    }
};