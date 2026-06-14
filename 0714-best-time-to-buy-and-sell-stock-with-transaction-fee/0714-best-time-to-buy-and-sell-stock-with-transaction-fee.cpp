class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // SPACE OPTIMIZATION with 4 VARIABLES

        int nextBuy = 0 , nextNotBuy = 0 ;
        int currBuy , currNotBuy ;

        for(int i = n-1 ; i >= 0 ; i--){
            
            // buy case
            currBuy = max(-prices[i] + nextNotBuy , 0 + nextBuy);
            // sell case
            currNotBuy = max(-fee + prices[i] + nextBuy , 0 + nextNotBuy);

            nextBuy = currBuy;
            nextNotBuy = currNotBuy;
        }

        return nextBuy;
    }
};