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

    int solve(string& s, int k , int i , int j, vector<vector<int>>& dp, vector<vector<bool>>& isPallindrome){
        // BASE CASE:
        int n = s.size();
        if(i >= n || j >= n){
            return 0 ;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // if pallindrome found     
        int take = INT_MIN ;

        if(isPallindrome[i][j]){
            take = 1 + solve(s, k , j+1, j+k, dp, isPallindrome);
        }

        // pallindrome not possible
        int grow = solve(s, k, i, j+1, dp, isPallindrome);
        int slide = solve(s, k, i+1, j+1, dp, isPallindrome);

        return dp[i][j] = max({take, grow, slide});
    }

    int maxPalindromes(string s, int k) {
        
        // giving TLE for k = 1 and s size very large --> handle that edge case
        if(k == 1) return s.size();

        int n = s.size();

        // creating isPallindrome 2D vector
        vector<vector<bool>> isPallindrome(n, vector<bool>(n , false));

        // fill isPallindrome
        createIsPallindrome(isPallindrome , s);

        // memoization vector
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(s, k, 0 , k-1, dp, isPallindrome);
    }
};