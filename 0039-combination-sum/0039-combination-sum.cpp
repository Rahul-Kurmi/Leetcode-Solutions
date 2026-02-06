class Solution {
public:

    vector<vector<int>> ans;

    void findingCombinationSum(vector<int>& arr, int target , int sum , vector<int>& store, int start){
        if(sum == target){
            ans.push_back(store);
            return ;
        }
        if(sum > target || start >= arr.size()) return ;

        for(int i = start ; i < arr.size() ; i++){
            store.push_back(arr[i]);
            findingCombinationSum(arr, target - arr[i] , sum , store , i);
            store.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store ;
        findingCombinationSum(candidates , target , 0 , store, 0);
        return ans ;
    }
};