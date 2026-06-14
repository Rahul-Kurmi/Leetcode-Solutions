class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // SPACE OPTIMIZATION
        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit ;
                if(buy){
                    int buyProfit = -prices[i] + next[0];
                    int skipProfit = 0 + next[1];
                    profit = max(buyProfit , skipProfit);
                }
                else{ // we're paying transaction fee at each full transaction
                    int sellProfit = -fee + prices[i] + next[1];
                    int skipProfit = 0 + next[0];
                    profit = max(sellProfit , skipProfit);
                }

                curr[buy]=  profit ;
            }
            next = curr;
        }

        return next[1];
    }
};