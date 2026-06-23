class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0 ;

        vector<vector<bool>> dp(n+1, vector<bool>(n+1 , false));

        for(int len = 1 ; len <= n ; len++){
            for(int i = 0 ; i + len - 1  < n ; i++){
                int j = i + len - 1 ;
                if(i == j){ // single char is pallindrome
                    dp[i][j] = true ;
                }
                else if(i+1 == j){ // two characters
                    dp[i][j] = (s[i] == s[j]);
                }
                else{ // Generic
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }


                if(dp[i][j]){ // current substr is pallindrome
                    count++;
                }
            }
        }

        return count ;
    }
};