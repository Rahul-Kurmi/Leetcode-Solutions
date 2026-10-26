class Solution {
public:

    vector<vector<int>> directions = {{1,0} , {0, 1}, {-1,0}, {0, -1}};
    void dfs(int i , int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int& sum, int k){
        int m = grid.size();
        int n = grid[0].size();

        if(grid[i][j] == 0 || visited[i][j]) return ;

        sum = (sum % k + grid[i][j]) % k;

        visited[i][j] = 1 ;

        for(auto dir : directions){
            int _i = i + dir[0];
            int _j = j + dir[1];

            if(_i >= 0 && _j >= 0 && _i < m && _j < n){
                dfs(_i , _j , grid, visited, sum, k);
            }
        }
        
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m , vector<int>(n , 0));

        int count = 0 ;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int sum = 0 ;
                if(grid[i][j] != 0 && !visited[i][j]){
                    dfs(i , j , grid, visited, sum, k);

                    // Count this island if its sum is divisible by k
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count ;
    }
};