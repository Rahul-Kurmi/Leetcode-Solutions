class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums[i].size(); j++){
                int rowColSum = i+j ;
                mp[rowColSum].push_back(nums[i][j]);
            }
        }

        vector<int> ans ;
        for(auto it : mp){
            vector<int> store = it.second ;
            reverse(store.begin() , store.end());
            for(auto ele : store) ans.push_back(ele);
        }

        return ans ;
    }
};