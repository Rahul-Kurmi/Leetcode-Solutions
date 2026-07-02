class Solution {
public:
    vector<string> result ;
    unordered_set<string> dict;

    void solve(string &s , int start, string &store){
        if(start == s.size()){
            result.push_back(store);
            return ;
        }

        for(int i = start ; i < s.size() ; i++){
            string tempWord = s.substr(start , i - start + 1);

            if(dict.find(tempWord) != dict.end()){
                string originalString = store; // store for backtracking
                if(!store.empty()){ // only push space in middle
                    store += " "; 
                }
                
                store += tempWord ;
                solve(s , i+1 , store);
                store = originalString ; // backtrack 

            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) {
            dict.insert(word);
        }

        string store = "";
        solve(s, 0 , store);

        return result ;

    }
};