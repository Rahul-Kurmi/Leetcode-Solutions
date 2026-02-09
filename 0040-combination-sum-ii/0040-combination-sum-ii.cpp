class Solution {
public:
    vector<vector<int>> ans;

    void findingAns(vector<int>& arr, int target, int sum, vector<int>& store, int i) {

        if (sum == target) {
            ans.push_back(store);
            return;
        }

        if (sum > target || i == arr.size()) return;

        // ✅ INCLUDE current element
        store.push_back(arr[i]);
        findingAns(arr, target, sum + arr[i], store, i + 1);
        store.pop_back();

        // ✅ EXCLUDE current element
        // skip all duplicates of arr[i]
        int next = i + 1;
        while (next < arr.size() && arr[next] == arr[i]) {
            next++;
        }
        
        findingAns(arr, target, sum, store, next);
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> store;
        findingAns(candidates, target, 0, store, 0);
        return ans;
    }
};
