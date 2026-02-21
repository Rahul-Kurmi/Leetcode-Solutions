class Solution {
public:
    vector<vector<int>> ans ;
    void findingAns(vector<int>& nums, int start, vector<int>& store){
        if(store.size() >= 2){
            ans.push_back(store);
        }

        if(start == nums.size()){
            return ;
        }

        unordered_map<int,  bool > isVisited ;
        for(int i = start ; i < nums.size() ; i++){
            if(isVisited[nums[i]]) continue ;
            isVisited[nums[i]] = true ;

            if(store.empty() || store[store.size() - 1 ] <= nums[i]){
                store.push_back(nums[i]);
                findingAns(nums, i+1, store);
                store.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> store;
        findingAns(nums, 0 , store);
        return ans ;
    }
};