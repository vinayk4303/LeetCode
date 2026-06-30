class Solution(object):
    def maxProfit(self, prices):
        if not prices:
            return 0
            
        max_profit = 0
        mini = prices[0]
        
        
        for price in prices:
            mini = min(mini, price)
            cost = price - mini
            max_profit = max(max_profit, cost)
            
        return max_profit