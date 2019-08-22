
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
2019-08-22
*/

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        if len(prices) == 0: 
            return 0
        
        # track min element seen and max profit
        buy = 0
        max_profit = 0
        
        for i in range(len(prices)):
            if prices[i] < prices[buy]: 
                buy = i
            elif prices[i] - prices[buy] > max_profit:
                max_profit = prices[i] - prices[buy]
        
        return max_profit
        