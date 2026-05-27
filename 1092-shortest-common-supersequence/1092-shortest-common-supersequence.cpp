class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        // code for shortest common super-subsequence
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>dp(m + 1 , vector<int> (n + 1 , 0));
        
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                
                if(i == 0 || j == 0) {
                    dp[i][j] = i+j;
                    continue ;
                }    
            
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }
                else{
                    // dp[i][j] = min(1 + dp[i-1][j] ,1 + dp[i][j-1]); same as below
                    dp[i][j] = 1 + min(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }


        // printing SCSS(shortest common super-subsequence)
        string result = "" ;
        int i = m;
        int j = n;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                result += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] < dp[i][j-1]){
                result += s1[i-1];
                i--;
            }
            else{
                result += s2[j-1];
                j--;
            }
        }

        // add remaining of s1 if left 
        while(i > 0){
            result += s1[i-1];
            i--;
        }

        // add remaining of s2 if left 
        while(j > 0){
            result += s2[j-1];
            j--;
        }

        reverse(result.begin() , result.end());
        return result ;
    }
};