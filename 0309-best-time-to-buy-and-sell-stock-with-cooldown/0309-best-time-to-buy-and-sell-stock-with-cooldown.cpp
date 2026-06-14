class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2 , vector<int>(2, 0));
        // TABULATION CODE

        // BASE CASE dp[n] = 0 ; no need to write as all initialized with 0

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit ;
                if(buy){
                    int buyProfit = -prices[i] + dp[i+1][0];
                    int skipProfit = 0 + dp[i+1][1];
                    profit = max(buyProfit, skipProfit);
                }
                else{ // buy = 0, means can sell only
                    int sellProfit = prices[i] + dp[i+2][1];
                    int skipProfit = 0 + dp[i+1][0];
                    profit = max(sellProfit , skipProfit);
                }

                dp[i][buy] = profit ;
            }
        }

        return dp[0][1];
    }
};