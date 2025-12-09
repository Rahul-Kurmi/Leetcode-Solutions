class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0 ;
        int finalVal = 0;
        for(int i = 0 ; i < accounts.size() ; i++){
            for(int j = 0 ; j < accounts[i].size() ; j++){
                ans = ans + accounts[i][j];
            }
            if(finalVal < ans){
                finalVal = ans ;
            }
            ans = 0 ;
        }
        return finalVal;
    }
};