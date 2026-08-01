class Solution {
public:
    int solve(vector<int>& nums, int start , int end, vector<vector<int>>& dp){
        if(start == end) return nums[start];

        if(dp[start][end] != -1) return dp[start][end];

        // diff = P1 - P2
        int diffByStart = nums[start] - solve(nums, start+1 , end, dp);
        int diffByEnd = nums[end] - solve(nums, start, end-1, dp);

        return dp[start][end] = max(diffByStart , diffByEnd);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1, 0));
        // TABULATION
        // BASE  CASE
        for(int i = 0 ; i < n ; i++) dp[i][i] = nums[i]; 

        for(int start = n-1 ; start >= 0 ; start--){
            for(int end = start + 1  ; end < n ; end++){
                // diff = P1 - P2
                int diffByStart = nums[start] - dp[start+1][end];
                int diffByEnd = nums[end] - dp[start][end-1];

                dp[start][end] = max(diffByStart , diffByEnd);
            }
        }

        return dp[0][n-1] >= 0;
    }
};