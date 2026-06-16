class Solution {
public:
    bool checkWord(string& word, vector<string>& wordDict){
        for(auto it : wordDict){
            if(it == word) return true ;
        }
        return false ;
    }

    // MEMOIZATION
    bool wordBreakHelper(string& s, vector<string>& wordDict, int start, vector<int>& dp){
        if(start == s.size()) return true ;

        if(dp[start] != -1) return dp[start]; 

        // one case make a string 
        string word = "";
        bool flag = false ;
        for(int i = start ; i < s.size(); i++){
            word += s[i];
            if(checkWord(word, wordDict)){
                flag = flag || wordBreakHelper(s, wordDict, i+1, dp);
            }
        }

        return dp[start] = flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);

        // TABULATION 
        // BASE CASE --> if(start == s.size()) return true 

        dp[s.size()] = true ;

        for(int start = s.size() - 1 ; start >= 0 ; start--){
            string word = "";
            bool flag = false ;
            for(int i = start ; i < s.size(); i++){
                word += s[i];
                if(checkWord(word, wordDict)){
                    flag = flag || dp[i+1];
                }
            }

            dp[start] = flag;
        }

        return dp[0];
    }
};