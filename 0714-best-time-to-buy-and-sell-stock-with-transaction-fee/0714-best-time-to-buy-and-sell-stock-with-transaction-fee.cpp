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

        // TABULATION CODE
        vector<vector<int>> dp(n+1 , vector<int>(2, 0));
        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit ;
                if(buy){
                    int buyProfit = -prices[i] + dp[i+1][0];
                    int skipProfit = 0 + dp[i+1][1];
                    profit = max(buyProfit , skipProfit);
                }
                else{ // we're paying transaction fee at each full transaction
                    int sellProfit = -fee + prices[i] + dp[i+1][1];
                    int skipProfit = 0 + dp[i+1][0];
                    profit = max(sellProfit , skipProfit);
                }

                dp[i][buy]=  profit ;
            }
        }

        return dp[0][1];
    }
};