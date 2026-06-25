class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int strLen = 0 ;
        int startIdx ;

        vector<vector<bool>> dp(n+1, vector<bool>(n+1 , false));

        for(int len = 1 ; len <= n ; len++){
            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1;

                if(i == j){ // 1 length string
                    dp[i][j] = true ;
                }  
                else if(i+1 == j){ // 2 length string
                    dp[i][j] = (s[i] == s[j]);
                }
                else{ // Generic 
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j] && len> strLen){
                    strLen = len ; // can also do j-i+1 but no need as we're iterating on len
                    startIdx = i ;
                }
            }
        }

        return s.substr(startIdx, strLen);
    }
};