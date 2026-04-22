class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp ;
        for(auto it : nums){
            mp[it]++;
        }

        vector<pair<int, int>> store ;
        for(auto it : mp){
            store.push_back({it.first , it.second});
        }

        sort(store.begin() , store.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        vector<int>ans;
        int i = 0;
        while(i != k){
            ans.push_back(store[i].first);
            i++;
        }
        return ans;
    }
};