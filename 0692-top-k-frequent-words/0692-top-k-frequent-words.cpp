class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mp;
        for(auto word : words){
            mp[word]++;
        }

        vector<pair<int , string>> store ;
        for(auto it : mp){
            store.push_back({it.second , it.first});
        }

        auto lambda = [](pair<int, string>& a , pair<int, string>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first ;
        };

        sort(store.begin() , store.end() , lambda);

        vector<string> ans ;
        int i = 0;
        while(k--){
            ans.push_back(store[i].second);
            i++;
        }

        return ans ;
    }
};