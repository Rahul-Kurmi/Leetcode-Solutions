class Solution {
public:

    vector<vector<int>> directions = {{1,0} , {0,1}, {-1, 0}, {0, -1}};

    bool isClosed(int i , int j, vector<vector<int>>& grid ,  vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        
        visited[i][j] = true ;

        bool ans = true ;

        if(i == 0 || j == 0 || i == m-1 || j == n-1){
            ans = false ; // we got 0 at boundary 
        }


        for(auto dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && !visited[new_i][new_j] && grid[new_i][new_j] != 1){
                bool solve = isClosed(new_i, new_j, grid, visited);

                if (solve == false){ // we got 0 at boundary but we sill need to mark all connecred 0 as visited
                    ans = false ;
                }
                    
            }
            
        }


        return ans ;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int> (n , 0));

        int ans = 0 ;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j] && grid[i][j] == 0){
                    bool solve = isClosed(i, j , grid, visited);
                    if(solve) ans++;
                }
            }
        }

        return ans ;
    }
};