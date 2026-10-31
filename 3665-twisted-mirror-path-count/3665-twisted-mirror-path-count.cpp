class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(vector<vector<int>>& grid, int i, int j, bool isDown, vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j][isDown] != -1) {
            return dp[i][j][isDown];
        }

        // If current cell is 1
        if(grid[i][j] == 1) {
            if(isDown) {
                return dp[i][j][isDown] = solve(grid, i, j+1, false, dp);
            }
            else {
                return dp[i][j][isDown] = solve(grid, i+1, j, true, dp);
            }
        }

        // Move Right
        int moveRight = solve(grid, i, j+1, false, dp);

        // Move Down
        int moveDown = solve(grid, i+1, j, true, dp);

        return dp[i][j][isDown] = (moveRight + moveDown) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, -1))
        );

        return solve(grid, 0, 0, false, dp);
    }
};