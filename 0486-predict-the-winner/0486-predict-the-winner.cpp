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
        vector<vector<int>> dp(n+1 , vector<int>(n+1, -1));
        return solve(nums, 0 , n-1, dp) >= 0;
    }
};