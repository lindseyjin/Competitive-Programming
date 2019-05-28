/*
https://leetcode.com/problems/3sum/submissions/
05-16-2019
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        if (nums.size() < 3) return ans;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // i is all possible first elements, avoid duplicates
            if (i != 0 && nums.at(i) == nums.at(i-1)) continue;
            
            int sum = 0 - nums.at(i); // what we want a pair to sum to
            
            int left = i+1, right = nums.size() - 1;
            while (left < right) {
                if (nums.at(left) + nums.at(right) == sum) {
                    ans.push_back({nums.at(i), nums.at(left), nums.at(right)});
                    left++;
                    while (left < right && nums.at(left) == nums.at(left-1)) left++;
                    right--;
                    while (right > left && nums.at(right) == nums.at(right+1)) right--;
                } else if (nums.at(left) + nums.at(right) < sum) left++;
                else right--;
            }

        }
        
        return ans;
    }
};