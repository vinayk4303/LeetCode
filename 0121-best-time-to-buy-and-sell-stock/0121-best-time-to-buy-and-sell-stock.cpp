class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int mini = prices[0];
        for (int i = 0; i < prices.size(); i++){
            mini = min(mini, prices[i]);
            int cost = prices[i] - mini;
            max_profit = max(max_profit, cost);
        }
        return max_profit;
    }
};