class Solution {
public:
    int solveForP1(vector<int>& nums , int i, int j, vector<vector<int>>& dp){
        if(i > j) return 0 ;
        if(i == j) return nums[i];

        if(dp[i][j] != -1) return dp[i][j];

        int take_i = nums[i] + min(solveForP1(nums, i+2 , j, dp), solveForP1(nums, i+1, j-1, dp));
        int take_j = nums[j] + min(solveForP1(nums, i+1, j-1, dp), solveForP1(nums, i, j-2, dp));

        return dp[i][j] =  max(take_i , take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        int player1Sum = solveForP1(nums, 0 , n-1, dp);
        int player2Sum = totalSum - player1Sum ;

        return player1Sum >= player2Sum ;
    }
};