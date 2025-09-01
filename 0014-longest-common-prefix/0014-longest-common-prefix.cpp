class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans = "" ;
        string first = strs[0];
        for(int i = 0 ; i < first.size() ; i++){
            char ch = first[i] ;
            for(int j = 1 ; j < strs.size() ; j++){
                string word = strs[j];
                if(ch != word[i]){
                    return ans ;
                }
            }
            ans = ans + ch ;
        }
        return ans ; 
    }
};