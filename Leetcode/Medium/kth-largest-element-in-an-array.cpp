/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
2019-11-10
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // heapify
        std::make_heap(nums.begin(), nums.end());
        
        // delete max k times
        for (int i = 0; i < k-1; ++i) {
            pop_heap (nums.begin(), nums.end()); nums.pop_back();
        }
        
        return nums[0];
    }
};