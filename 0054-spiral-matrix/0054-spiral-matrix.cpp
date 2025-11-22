class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns

        int starting_row = 0;
        int ending_row = m - 1;
        int starting_col = 0;
        int ending_col = n - 1;
        int total_element = m * n;

        int count = 0;
        while (count < total_element) {
            // Print starting row
            for (int i = starting_col; i <= ending_col && count < total_element; i++) {
                ans.push_back(matrix[starting_row][i]);
                count++;
            }
            starting_row++;

            // Print ending column
            for (int i = starting_row; i <= ending_row && count < total_element; i++) {
                ans.push_back(matrix[i][ending_col]);
                count++;
            }
            ending_col--;

            // Print ending row
            for (int i = ending_col; i >= starting_col && count < total_element; i--) {
                ans.push_back(matrix[ending_row][i]);
                count++;
            }
            ending_row--;

            // Print starting column
            for (int i = ending_row; i >= starting_row && count < total_element; i--) {
                ans.push_back(matrix[i][starting_col]);
                count++;
            }
            starting_col++;
        }
        return ans ;
    }
};