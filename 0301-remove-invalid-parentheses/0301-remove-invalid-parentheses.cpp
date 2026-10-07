class Solution {
public:
    unordered_set<string> storeAns ;
    int maxLen = 0 ;
    
    void solve(string& s , int i , int count, string &store){
        if(count < 0) return ; // invalid string

        if(i == s.size()){
            if(count == 0){ // formed a valid string
                if(store.size() > maxLen){
                    storeAns.clear();
                    storeAns.insert(store);
                    maxLen = store.size();
                }
                else if(store.size() == maxLen){
                    storeAns.insert(store);
                }
            }

            return ;
        }

        if(s[i] != '(' && s[i] != ')'){ // means it's a lowercase character
            store.push_back(s[i]);
            solve(s, i+1, count , store);
            store.pop_back();
            return ; // early return as lowercase no need to check below ones 
        }


        // check for s[i] is '(' or ')'
        store.push_back(s[i]);
        solve(s, i+1, s[i] == '(' ? count + 1 : count - 1 , store);
        store.pop_back();


        // we skip currebt braces
        solve(s, i+1, count , store);
    }

    vector<string> removeInvalidParentheses(string s) {
        string store = "";
        solve(s, 0, 0, store);

        vector<string> result ;
        for(auto it: storeAns){
            result.push_back(it);
        }

        return result ;
    }
};