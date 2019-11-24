/**
https://leetcode.com/problems/3sum-closest/
2019-11-17
**/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest, first, l, r, sum;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i != 0) {
                while (nums[i] == first) {
                    i++;   
                    if (i >= nums.size()-2) break;
                }
            }
            first = nums[i];
            l = i+1;
            r = nums.size()-1;   
            sum = first + nums[l] + nums[r];
            if (i == 0) closest = sum;
            
            while (l+1 < r) {
                if (abs(target - sum) < abs(target - closest)) closest = sum;
                
                if (sum < target) l++;
                else if (sum > target) r--;
                else return target;
                
                sum = first + nums[l] + nums[r];
            }
            
            if (abs(target - sum) < abs(target - closest)) closest = sum;
        }
        
        return closest;
    }
};