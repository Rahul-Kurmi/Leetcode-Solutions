class Solution {
public:
    // find LCS --> length

    int topDownSolve(string& word1, string& word2, int i , int j , vector<vector<int>>& dp){
        if(i == 0 || j == 0) return 0 ;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = 1 + topDownSolve(word1 , word2, i-1 , j-1 , dp);
        }
        else{
            return dp[i][j] = max(topDownSolve(word1, word2, i-1, j , dp) , topDownSolve(word1, word2, i, j-1, dp));
        }
    }


    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

        // get the LCS length 
        int matchLen = topDownSolve(word1, word2 , m , n , dp);

        // remove the lcs length from both and add --> that is the no. of steps required
        int ans = (m-matchLen) + (n - matchLen);
        return ans ;
    }
};