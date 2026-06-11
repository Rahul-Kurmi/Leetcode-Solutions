class Solution {
public:
    int numSquarehelper(int n, vector<int>& dp){
        // Base Case 
        if (n==0) return 1 ;
        if (n<0) return 0 ;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX ;
        int i = 1 ;
        int end = sqrt(n);
        while(i<=end){
            int perfectSquare = i*i ;
            int numberOfPrefectSquare = 1 + numSquarehelper(n-perfectSquare, dp);
            if(numberOfPrefectSquare<ans){
                ans = numberOfPrefectSquare;
            }
            ++i;
        }
        return dp[n] = ans ;
        
    }

    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 1 ;

        for(int index = 1 ; index <= n ; index++){
            int ans = INT_MAX ;
            int i = 1 ;
            int end = sqrt(index);
            while(i<=end){
                int perfectSquare = i*i ;
                int numberOfPrefectSquare = 1 + dp[index-perfectSquare];
                if(numberOfPrefectSquare<ans){
                    ans = numberOfPrefectSquare;
                }
                ++i;
            }
            dp[index] = ans ;
        }

        return dp[n] - 1 ;

    }
};