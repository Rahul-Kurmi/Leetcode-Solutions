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

    int maxPalindromes(string s, int k) {
        
        // giving TLE for k = 1 and s size very large --> handle that edge case
        if(k == 1) return s.size();

        int n = s.size();

        // creating isPallindrome 2D vector
        vector<vector<bool>> isPallindrome(n, vector<bool>(n , false));

        // fill isPallindrome
        createIsPallindrome(isPallindrome , s);

        // TABULATION CODE 
        vector<vector<int>> dp(n + 1, vector<int>(n + 1 , 0));

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                // if pallindrome found     
                int take = INT_MIN ;

                if(isPallindrome[i][j]){
                    // add check for j+k for out of bound errors
                    take = 1 + (j + k < n ? dp[j+1][j+k] : 0);
                }

                // pallindrome not possible
                int grow = dp[i][j+1];
                int slide = dp[i+1][j+1];

                dp[i][j] = max({take, grow, slide});
            }
        }

        return dp[0][k-1]; 
    }
};