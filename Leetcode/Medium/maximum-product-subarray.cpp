/*
https://leetcode.com/problems/maximum-product-subarray/
2019-11-10
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1;
        int largest = nums[0];
        int neg = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            if (product > largest) largest = product;
            
            if (product == 0) {    
                while (nums[i] == 0) {
                    i++;
                    if (i >= nums.size()) return largest;
                }
                product = nums[i];
                if (product > largest) largest = product;
                neg = (product < 0) ? product : 0;

            } else if (product < 0) {
                if (neg == 0) neg = product;
                else if (product/neg > largest) largest = product/neg;
            }            
        }
        
        return largest;
    }
};