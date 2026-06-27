class Solution {
public:
    void solve(string& s , int start , vector<string>& currPartition , vector<vector<string>>& result , vector<vector<bool>>& dp){
        if(start == s.size()){
            result.push_back(currPartition);
            return ;
        }

        for(int i = start ; i < s.size() ; i++){
            if(dp[start][i] == true){
                currPartition.push_back(s.substr(start , i - start + 1));
                solve(s , i+1 , currPartition, result , dp);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = 0 ; i < n ; i++){
            dp[i][i] = true ; // substring of single character is always pallindrome
        }

        for(int len = 2; len <= n ; len++){
            for(int i = 0 ; i < n - len + 1 ; i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(len == 2) dp[i][j] = true ;
                    else dp[i][j] = dp[i+1][j-1];
                } 
            }
        }

        vector<vector<string>> result ;
        vector<string> currPartition ;
        solve(s, 0 , currPartition,  result , dp);

        return result ;
    }
};