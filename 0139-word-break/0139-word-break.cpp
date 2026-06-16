class Solution {
public:
    unordered_set<string> st;
    int n;
    
    bool solve(string &s, int idx, vector<int>& dp) {
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr(idx)) != st.end()) {
            return true;
        }

        if(dp[idx]!= -1) return dp[idx] ;
        
        for(int len = 1; len<=n; len++) {   
            string temp = s.substr(idx, len);
            if(st.find(temp) != st.end() && solve(s, idx+len, dp))
                return dp[idx] = true;
            
        }
        
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        for(string &word : wordDict) {
            st.insert(word);
        }

        vector<int> dp(n , -1);
        
        return solve(s, 0, dp);
    }
};