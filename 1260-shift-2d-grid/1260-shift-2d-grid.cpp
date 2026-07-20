class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k = k % (m*n);
        if(k == 0) return grid ;

        vector<vector<int>> store(m, vector<int>(n));

        while(k--){
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(j == n-1){
                        if(i == m-1){
                            store[0][0] = grid[m-1][n-1];
                        }
                        else{
                            store[i+1][0] = grid[i][n-1];
                        }
                    }
                    else{
                        store[i][j+1] = grid[i][j];
                    }
                }
            }

            grid = store ;
        }
        return store ;
    }
};