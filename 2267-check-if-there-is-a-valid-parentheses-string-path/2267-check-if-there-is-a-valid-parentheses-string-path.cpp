class Solution {
public:
    bool solve(vector<vector<char>>& grid, int i, int j, int brace,  vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        // If we have more closing brackets than opening brackets
        if(brace < 0) return false;

        // Process current cell
        if(grid[i][j] == '(') brace++;
        else brace--;

        // Invalid path
        if(brace < 0) return false;


        // check if already exist
        if(dp[i][j][brace] != -1) return dp[i][j][brace];

        // Reached destination
        if(i == m-1 && j == n-1) {
            return dp[i][j][brace] = brace == 0;
        }

        // DOWN
        bool downAns = false;
        if(i+1 < m) {
            downAns = solve(grid, i+1, j, brace, dp);
        }

        // RIGHT
        bool rightAns = false;
        if(j+1 < n) {
            rightAns = solve(grid, i, j+1, brace, dp);
        }

        return dp[i][j][brace] = downAns || rightAns;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // total parenthesis length will be m * (n-1)  or (n-1) * m
        // As we can traverse all the row and n-1 col 

        // Also for a balanced parenthesis the total length will be even
        if((m+n-1) % 2 == 1) 
            return false;
        
        // Extra check 
        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m+n-1, -1)));
        return solve(grid, 0, 0, 0, dp);
    }
};