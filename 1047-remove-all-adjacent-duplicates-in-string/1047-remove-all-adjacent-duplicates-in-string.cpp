class Solution {
public:
    string removeDuplicates(string s) {
        if(s.size() <= 1) return s ;
        string ans = "";
        ans.push_back(s[0]);
        for(int i = 1 ; i < s.size() ; i++){
            if(ans.size() != 0 && s[i] == ans[ans.size() - 1] ){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};