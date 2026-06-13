class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // SPACE OPTIMIZED 
        int aheadNotBuy , aheadBuy = 0 ;
        int currNotBuy, currBuy ;

        for(int i = n-1 ; i >= 0 ; i--){
            currNotBuy = max(prices[i] + aheadBuy , 0 + aheadNotBuy);
            currBuy = max(-prices[i] + aheadNotBuy , 0 + aheadBuy);
            // SWAP
            aheadNotBuy = currNotBuy;
            aheadBuy = currBuy;
        }

        return aheadBuy;
    }
};