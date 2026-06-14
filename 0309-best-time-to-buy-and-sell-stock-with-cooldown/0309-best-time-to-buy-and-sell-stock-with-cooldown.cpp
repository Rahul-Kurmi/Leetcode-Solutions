class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+2 , vector<int>(2, 0));
        // as we have i+1,i+2 --> need 3, 1D vector for space optimized
        vector<int> nextNext(2, 0);
        vector<int> next(2, 0);
        vector<int> curr(2, 0);  

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit ;
                if(buy){
                    int buyProfit = -prices[i] + next[0];
                    int skipProfit = 0 + next[1];
                    profit = max(buyProfit, skipProfit);
                }
                else{ // buy = 0, means can sell only
                    int sellProfit = prices[i] + nextNext[1];
                    int skipProfit = 0 + next[0];
                    profit = max(sellProfit , skipProfit);
                }

                curr[buy] = profit ;
            }
            nextNext = next ;
            next = curr; 
        }

        return next[1];
    }
};