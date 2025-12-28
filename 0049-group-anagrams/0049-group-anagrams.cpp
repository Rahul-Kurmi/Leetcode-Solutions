class Solution {
public:
    array<int , 26> hash(string s){
        array<int , 26 > hash = {0};
        for(int i = 0 ; i < s.size() ;i++){
            hash[s[i] - 'a']++;
        }
        return hash ;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int ,26> , vector<string>> mp;

        for(auto it : strs){
            array<int, 26> hashedVal = hash(it);
            mp[hashedVal].push_back(it);            
        }

        vector<vector<string>> ans ;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans ; 

    }
};