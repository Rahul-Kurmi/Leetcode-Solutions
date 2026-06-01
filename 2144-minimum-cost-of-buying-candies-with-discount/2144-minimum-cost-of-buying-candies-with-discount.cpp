class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        
        int minCost = 0 ;
        for(int i = 0 ; i < cost.size() ; i++){
            if((i+1) % 3 == 0) continue ;
            minCost += cost[i];
        }

        return minCost ;
    }
};