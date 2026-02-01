class Solution {
public:
    void permutations(vector<int>& arr , vector<vector<int>>& ans , int i){
        if(i >= arr.size()){
            ans.push_back(arr);
        }

        for(int j = i ; j < arr.size() ; j++){
            swap(arr[i] , arr[j]);
            permutations(arr, ans , i+1);
            swap(arr[i] , arr[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        permutations(nums , ans , 0);
        return ans;
    }
};