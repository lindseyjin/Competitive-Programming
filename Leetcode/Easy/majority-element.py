# https://leetcode.com/problems/majority-element
# 2019-11-10

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        majority = 0;
        freq = {0:0};
        
        for i in nums: 
            if i in freq:
                freq[i] += 1;
            else: 
                freq[i] = 1;
            if freq[i] > len(nums)/2+1:
                return majority
            if freq[i] > freq[majority]:
                majority = i
        
        return majority;
        