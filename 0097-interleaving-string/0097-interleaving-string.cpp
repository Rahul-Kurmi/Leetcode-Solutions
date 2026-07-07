class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp) {

        if(i == s1.size() && j == s2.size()){
            return true;
        }

        int k = i + j;

        if(dp[i][j] != -1)
            return dp[i][j];

        bool result = false;

        if(i < s1.size() && s1[i] == s3[k]){
            result = solve(s1, s2, s3, i + 1, j, dp);
        }

        // Early return so that true is not overwritten
        if(result){
            return dp[i][j] = true;
        }

        if(j < s2.size() && s2[j] == s3[k]){
            result = solve(s1, s2, s3, i, j + 1, dp);
        }

        return dp[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        
        // TABULATION CODE 

        if(s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size();
        int n = s2.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true ; // BC

        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){

                if(i == m && j == n){ // already stored base case
                    continue; 
                }
                // why start from i = m , j = n
                // As we want to store ans when i = m and j = 0 --> n-1 
                // also when j = n and i = 0 --> m-1

                // Start from (m, n) because states on the last row (i = m)
                // and last column (j = n) are also valid DP states.
                // They represent the cases where one string is completely
                // consumed while the other still has characters remaining.

                int k = i + j;
                bool result = false;

                if(i < m && s1[i] == s3[k])
                    result = dp[i+1][j];

                if(result){
                    dp[i][j] = true;
                    continue;
                }

                if(j < n && s2[j] == s3[k])
                    result = dp[i][j+1];

                dp[i][j] = result;
            }
        }

        return dp[0][0];
    }
};