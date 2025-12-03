class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> diffs ;
        for(int i = 0 ; i < arr.size() ; i++){
            int diff = abs(x - arr[i]);
            diffs.push_back({diff,arr[i]});
        }

        sort(diffs.begin() , diffs.end());

        vector<int> ans;
        int i = 0 ;
        while(k > 0){
            ans.push_back(diffs[i].second);
            i++;
            k--;
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};