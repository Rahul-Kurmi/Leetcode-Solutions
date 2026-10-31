class Solution {
public:
    int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

        // Base case: Destination
        dp[m-1][n-1][0] = 1;
        dp[m-1][n-1][1] = 1;

        // Traverse from bottom-right to top-left
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                // Destination already initialized
                if(i == m-1 && j == n-1) continue;

                // If current cell is 1
                if(grid[i][j] == 1) {

                    // Arrived by moving RIGHT
                    dp[i][j][0] = dp[i+1][j][1];

                    // Arrived by moving DOWN
                    dp[i][j][1] = dp[i][j+1][0];
                }

                else {

                    int moveRight = dp[i][j+1][0];
                    int moveDown = dp[i+1][j][1];

                    int total = (moveRight + 1LL * moveDown) % MOD;

                    dp[i][j][0] = total;
                    dp[i][j][1] = total;
                }
            }
        }

        return dp[0][0][0];
    }
};