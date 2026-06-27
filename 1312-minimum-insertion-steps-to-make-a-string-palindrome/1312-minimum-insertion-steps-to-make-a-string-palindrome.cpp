class Solution {
public:
    // From the same bluprint of Longest palindromic substring 
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n , 0));

        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 0 ; // single char is already pallindrome 
        }


        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 ; len + i - 1 < n; i++){
                int j = len + i - 1;
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};