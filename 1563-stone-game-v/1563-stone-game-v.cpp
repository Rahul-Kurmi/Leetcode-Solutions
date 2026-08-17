class Solution {
public:
    int getSum(vector<int>& stoneValue, int i, int j) {
        int sum = 0;

        while(i <= j) {
            sum += stoneValue[i];
            i++;
        }

        return sum;
    }

    int solve(vector<int>& stoneValue, int start, int end, vector<vector<int>>& dp){
        if(start == end)
            return 0;
        
        if(dp[start][end] != -1) return dp[start][end];

        int totalSum = getSum(stoneValue, start, end);

        int currSum = 0;
        int maxSum = 0;

        // divide at every possible position
        for(int i = start; i < end; i++) {

            currSum += stoneValue[i];

            int leftSum = currSum;
            int rightSum = totalSum - leftSum;

            if(leftSum < rightSum) { // when righSum > leftSum, bob will remove rightSum
                maxSum = max(maxSum, leftSum + solve(stoneValue, start, i, dp));
            }
            else if(leftSum > rightSum) {
                maxSum = max(maxSum, rightSum + solve(stoneValue, i + 1, end, dp));
            }
            else {  // when leftSum == rightSum, Alice will want to maximize the sum 
                maxSum = max(maxSum,
                    max(
                        leftSum + solve(stoneValue, start, i, dp),
                        rightSum + solve(stoneValue, i + 1, end, dp)
                    )
                );
            }
        }

        return dp[start][end] =  maxSum;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1 , -1));
        return solve(stoneValue, 0, n - 1, dp);
    }
};