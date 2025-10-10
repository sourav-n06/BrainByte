class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int x : prices) {
            int cost = x - mini;
            profit = max(cost, profit);
            mini = min(mini, x);
        }

        return profit;
    }
};