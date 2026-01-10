class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyStock = INT_MAX ;
        int maxProfit = 0 ;
        for(int i = 0 ; i < prices.size() ; i++){
            if(buyStock > prices[i]){
                buyStock = prices[i];
            }
            if((prices[i] - buyStock) > maxProfit){
                maxProfit = prices[i] - buyStock ;
            }
        }
        return maxProfit ;
    }
};