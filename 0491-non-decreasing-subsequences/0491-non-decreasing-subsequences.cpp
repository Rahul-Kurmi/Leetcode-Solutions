class Solution {
public:
    vector<vector<int>> ans;

    void findingAns(vector<int>& nums, int i, vector<int>& store, int lastIncluded){
        // Base case
        if(i == nums.size()){
            if(store.size() >= 2){
                ans.push_back(store);
            }
            return;
        }

        // INCLUDE current element (if valid)
        if(store.empty() || store.back() <= nums[i]){
            store.push_back(nums[i]);
            findingAns(nums, i + 1, store, nums[i]);
            store.pop_back();
        }

        // EXCLUDE current element
        // Skip if current element equals the last included element
        // This prevents: [4] -> skip 7 -> [4] -> include 7 (duplicate path)
        if(nums[i] != lastIncluded){
            findingAns(nums, i + 1, store, lastIncluded);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> store;
        findingAns(nums, 0, store, INT_MIN);
        return ans;
    }
};