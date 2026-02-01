class Solution {
public:
    void solve(vector<int>& nums , int i , vector<vector<int>>& ans, vector<int> store){
        if(i == nums.size()){
            ans.push_back(store);
            return ;
        }

        // Include 
        store.push_back(nums[i]);
        solve(nums , i+1 , ans, store);
        store.pop_back();

        //Exclude 
        solve(nums , i+1 , ans , store);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> store;
        solve(nums, 0, ans , store);
        return ans ;
    }
};