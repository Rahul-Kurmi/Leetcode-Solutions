class Solution {
public:
    // PRE-REQUISITE :- Buy And Sell 2
    int maxProfitHelper(vector<int>& prices, int i, int buy, int& fee, vector<vector<int>>& dp){
        if(i == prices.size()) return 0 ;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit ;
        if(buy){
            int buyProfit = -prices[i] + maxProfitHelper(prices, i+1, 0 , fee, dp);
            int skipProfit = 0 + maxProfitHelper(prices, i+1, 1, fee, dp);
            profit = max(buyProfit , skipProfit);
        }
        else{ // we're paying transaction fee at each full transaction
            int sellProfit = -fee + prices[i] + maxProfitHelper(prices, i+1, 1, fee, dp);
            int skipProfit = 0 + maxProfitHelper(prices, i+1, 0 , fee, dp);
            profit = max(sellProfit , skipProfit);
        }

        return dp[i][buy]=  profit ;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2, -1));
        return maxProfitHelper(prices, 0 , 1, fee, dp);
    }
};