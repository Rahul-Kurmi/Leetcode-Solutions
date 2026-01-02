class Solution {
public:
    bool isPallindrome(string str){
        for(int i = 0 ; i < str.size()/2 ; i++){
            if(str[i] != str[str.size() - i -1]){
                return false;
            }
        }
        return true ;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string , int> mp ;
        for(int i = 0 ; i < words.size() ; i++){
            string str = words[i];
            reverse(str.begin() , str.end());
            mp[str] = i ;
        }

        if(mp.find("") != mp.end()){
            for(int i = 0 ; i < words.size() ; i++){
                if(words[i] != "" && isPallindrome(words[i])){
                    ans.push_back({i , mp[""]});
                }
            } 
        }

        for(int i = 0 ; i < words.size() ; i++){
            string left , right ;
            for(int j = 0 ; j < words[i].size() ; j++){
                left  = words[i].substr(0 , j + 1);
                right = words[i].substr(j + 1 , words[i].size() - j);

                if(mp.find(left) != mp.end() && isPallindrome(right) && mp[left] != i){
                    ans.push_back({i , mp[left]});
                }

                if(mp.find(right) != mp.end() && isPallindrome(left) && mp[right] != i){
                    ans.push_back({mp[right] , i});
                }
            }
        }

        return ans ;
    }
};