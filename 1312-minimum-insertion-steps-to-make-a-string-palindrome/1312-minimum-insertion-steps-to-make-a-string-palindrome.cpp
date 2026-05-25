class Solution {
public:

    int lcs(string& s , string& t , int i , int j , vector<vector<int>>& dp){
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int result = 0 ;
        if(s[i - 1] == t[j - 1]){
            result = 1 + lcs(s , t, i - 1, j - 1, dp);
        }
        else{
            result = max(lcs(s, t, i, j - 1, dp) , lcs(s, t, i- 1, j, dp));
        }

        return dp[i][j] =  result ;
    }

    int minInsertions(string s) {
        string t = s ;
        reverse(t.begin() , t.end());
        int n = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1, -1));
        int longPallSubsequence = lcs(s , t, n, n, dp);
        return n - longPallSubsequence ;
    }
};