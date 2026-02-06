class Solution {
public:
    vector<vector<int>> ans;

    void findingCombinationSum(vector<int>& arr, int target , vector<int>& store, int i){
        if(target == 0){
            ans.push_back(store);
            return ;
        }
        if(target < 0 || i >= arr.size()) return ;

        // Include Case
        store.push_back(arr[i]);
        findingCombinationSum(arr, target - arr[i] , store, i);
        store.pop_back();

        // Exclude Case 
        findingCombinationSum(arr, target , store , i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store ;
        findingCombinationSum(candidates , target ,  store, 0);
        return ans ;
    }
};