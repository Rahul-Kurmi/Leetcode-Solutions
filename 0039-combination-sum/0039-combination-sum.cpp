class Solution {
public:
    vector<vector<int>> ans;

    void findingCombinationSum(vector<int>& arr, int target , int sum , vector<int>& store, int i){
        if(sum == target){
            ans.push_back(store);
            return ;
        }
        if(sum > target || i >= arr.size()) return ;

        // Include Case
        store.push_back(arr[i]);
        findingCombinationSum(arr, target , sum+arr[i], store, i);
        store.pop_back();

        // Exclude Case 
        findingCombinationSum(arr, target , sum , store , i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store ;
        findingCombinationSum(candidates , target , 0 , store, 0);
        return ans ;
    }
};