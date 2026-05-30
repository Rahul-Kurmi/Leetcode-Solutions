class Solution {
public:
    int minDistanceHelper(string& s1, string& s2, int i , int j, vector<vector<int>>& dp){
        if(i == 0 || j == 0) return dp[i][j] = i+j;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]){
            return dp[i][j] =  0 + minDistanceHelper(s1, s2, i-1, j-1, dp);
        }
        else{
            int insertOp = minDistanceHelper(s1, s2, i, j-1, dp); // then matched
            int deleteOp = minDistanceHelper(s1, s2, i-1, j, dp); // delete from s1
            int replaceOp = minDistanceHelper(s1, s2, i-1 , j-1, dp); // replace i with j

            return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
        
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i = 0 ; i <= m ; i++) dp[i][0] = i ;
        for(int j = 0 ; j <= n ; j++) dp[0][j] = j ;

        for(int i = 1 ; i <= m ; i++){
            for(int j = 1; j <= n ; j++){

                if(word1[i-1] == word2[j-1]){
                    dp[i][j] =  0 + dp[i-1][j-1];
                }
                else{
                    int insertOp = dp[i][j-1]; // then matched
                    int deleteOp = dp[i-1][j]; // delete from s1
                    int replaceOp = dp[i-1][j-1]; // replace i with j

                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[m][n];
    }
};