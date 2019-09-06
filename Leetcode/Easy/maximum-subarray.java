/*
https://leetcode.com/problems/maximum-subarray
2019-09-05
*/

class Solution {
    public int maxSubArray(int[] nums) {
        // O(n) solution
        int sum = 0;
        int largest = nums[0];
        int b = 0, e = nums.length-1;
        
        // find last index before sum starts to decrease
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            if (sum > largest) {
                largest = sum;
                e = i;
            }
            
            if (sum < 0) sum = 0; // disregard previous
        }
        
        sum = 0;
        // go backwards to find beginning index
        for (int i = e; i >= 0; --i) {
            sum += nums[i];
            if (sum > largest) {
                largest = sum;
                b = i;
            }
        }
        
        return largest;
    }
}