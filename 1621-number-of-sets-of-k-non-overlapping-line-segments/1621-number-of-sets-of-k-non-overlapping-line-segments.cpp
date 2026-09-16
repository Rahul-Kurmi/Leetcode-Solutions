class Solution {
public:
    long long M = 1e9 + 7;

    int numberOfSets(int n, int K) {
        // Tabulation vector
        vector<vector<int>> dp(K + 1, vector<int> (n + 1 , 0));

        // BASE CASE
        // when k == 0 , we get one valid way 
        for(int start = 0 ; start <= n-1 ; start++){
            dp[0][start] = 1 ;
        }

        for(int k = 1 ; k <= K; k++){
            // OPTIMIZATION
            vector<int> suffixSum(n+1, 0);
            for(int x = n-1 ; x >= 0 ; x--){
                suffixSum[x] = (suffixSum[x+1] + dp[k-1][x]) % M;
            }

            for(int start = n-1 ; start >= 0 ; start--){
                // TAKE 
                int take = suffixSum[start+1] % M ;

                // SKIP 
                int skip = dp[k][start+1] % M;

                dp[k][start] =  (take + skip) % M ;
            }
        }

        return dp[K][0];
    }
};