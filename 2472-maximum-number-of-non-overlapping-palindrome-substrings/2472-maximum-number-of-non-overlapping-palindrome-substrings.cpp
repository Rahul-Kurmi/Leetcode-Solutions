class Solution {
public:
    void createIsPallindrome(vector<vector<bool>>& isPallindrome, string& s){
        int n = s.size();

        for(int len = 1 ; len <= n ; len++){
            for(int i = 0 ; i + len <= n ; i++){
                int j = i + len - 1;  
                // CASE 1 : size = 1
                if(i == j){
                    isPallindrome[i][j] = true ;
                } 
                else if(i + 1 == j){ // CASE 2 : size = 2
                    isPallindrome[i][j] = (s[i] == s[j]);
                }
                else{ // CASE 3 : size > 2 
                    isPallindrome[i][j] = (s[i] == s[j]) && (isPallindrome[i+1][j-1]);
                }
            }
        }
    }

    int solve(int len, int k,  string& s, vector<vector<bool>>& isPallindrome, vector<int>& dp){
        if(len < k) return 0; // BASE CASE

        if(dp[len] != -1) return dp[len];

        int result = solve(len - 1, k , s, isPallindrome, dp);
 
        int j = len - 1;

        for(int i = 0 ; j - i + 1 >= k ; i++){
            if(isPallindrome[i][j]){
                result = max(result , 1 + solve(i, k, s, isPallindrome, dp));
            }
        } 

        return  dp[len] = result ;
    }

    int maxPalindromes(string s, int k) {
        if(k == 1) return s.size();

        int n = s.size();

        vector<vector<bool>> isPallindrome(n, vector<bool>(n , false));
        createIsPallindrome(isPallindrome , s);

        // DP
        vector<int> dp(n + 1, -1);

        return solve(n, k, s, isPallindrome, dp);
    }
};