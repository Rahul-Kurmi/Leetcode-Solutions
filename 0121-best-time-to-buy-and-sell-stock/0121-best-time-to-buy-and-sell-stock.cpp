class Solution {
public:
    int highestProfit(vector<int>&prices , int i , int buyStock){
        if(i == prices.size() - 1 ){
            return (prices[i] - buyStock);
        }

        if(buyStock > prices[i]){
            buyStock = prices[i];
        }

        int profit = prices[i] - buyStock ;
        int recursionProfit = highestProfit(prices , i+1 , buyStock);
        return max(profit  , recursionProfit);

    }

    int maxProfit(vector<int>& prices) {
        return highestProfit(prices , 0 , prices[0]);
    }
};