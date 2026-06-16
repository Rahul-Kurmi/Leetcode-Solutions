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
                // flag = wordBreakHelper(s, wordDict, i+1);  --> WRONG
                // return flag = wordBreakHelper(s, wordDict, i+1); --> WRONG 
                flag = flag || wordBreakHelper(s, wordDict, i+1, dp);
                // OR DO 
                // flag = wordBreakHelper(s, wordDict, i+1);
                // if(flag) return true ;
            }
        }

        return dp[start] = flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() , -1);
        return wordBreakHelper(s, wordDict, 0, dp);
    }
};