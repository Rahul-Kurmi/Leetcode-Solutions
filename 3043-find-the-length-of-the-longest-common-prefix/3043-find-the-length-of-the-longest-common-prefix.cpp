class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, bool> mp;
        for(auto &it: arr1){
            string str = to_string(it);
            string store = "";
            for(int i = 0 ; i < str.size() ; i++){
                store += str[i];
                mp[store] = true;
            }
        }

        int maxPrefix = 0;
        for(auto &it: arr2){
            string str = to_string(it);
            string store = "";
            for(int i = 0 ; i < str.size() ; i++){
                store += str[i];
                if(mp.count(store)){
                    maxPrefix = max(maxPrefix, (int)store.size());
                }
            }
        }
        return maxPrefix;
    }
};