class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int& perimeter){
        // mark current visited
        grid[i][j] = -1 ;
        
        // move left 
        if(i-1 < 0 || grid[i-1][j] == 0){
            perimeter++;
        }
        else if(grid[i-1][j] == 1){
            dfs(i-1 ,  j , grid, perimeter);
        }


        // move up
        if(j-1 < 0 || grid[i][j-1] == 0){
            perimeter++;
        }
        else if(grid[i][j-1] == 1){
            dfs(i, j-1, grid, perimeter);
        }


        // move down
        if(i+1 == grid.size() || grid[i+1][j] == 0){
            perimeter++;
        }
        else if(grid[i+1][j] == 1){
            dfs(i+1, j, grid, perimeter);
        }

        // move right
        if(j+1 == grid[0].size() || grid[i][j+1] == 0){
            perimeter++;
        }
        else if(grid[i][j+1] == 1){
            dfs(i, j+1, grid, perimeter);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid[0].size();

       int perimeter = 0 ;
       for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1){
                    dfs(i, j , grid, perimeter);
                    break;
                }
            }
       }

       return perimeter ; 
    }
};