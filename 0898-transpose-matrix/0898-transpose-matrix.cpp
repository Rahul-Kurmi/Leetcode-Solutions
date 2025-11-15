class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows)); // Initialize ans with transposed dimensions

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                // 3*4 matrix ke liye chala ke dekh lo
                ans[j][i] = matrix[i][j]; 
            }
        }
        return ans;
    }
};