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

        if(s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(s1, s2, s3, 0, 0, dp);
    }
};