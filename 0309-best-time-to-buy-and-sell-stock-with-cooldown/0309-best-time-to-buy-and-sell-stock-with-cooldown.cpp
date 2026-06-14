class Solution {
public:
    int maxProfitHelper(vector<int>& prices, int i, int buy, vector<vector<int>>& dp){
        if(i >= prices.size()) {
            return 0 ;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit ;
        if(buy){
            int buyProfit = -prices[i] + maxProfitHelper(prices , i+1 , 0, dp);
            int skipProfit = 0 + maxProfitHelper(prices, i+1 , 1, dp);
            profit = max(buyProfit, skipProfit);
        }
        else{ // buy = 0, means can sell only
            int sellProfit = prices[i] + maxProfitHelper(prices, i+2 , 1, dp);
            int skipProfit = 0 + maxProfitHelper(prices , i+1 , 0, dp);
            profit = max(sellProfit , skipProfit);
        }

        return  dp[i][buy] = profit ;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2, -1)); 
        return maxProfitHelper(prices, 0 , 1, dp); // start buy = 1 as we must buy in start to sell
    }
};