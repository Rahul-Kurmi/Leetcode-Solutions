class Solution {
public:
     void getUniquePaths(vector<vector<int>>& grid, int row, int col, int zeroCount, int& finalAns){
        if(zeroCount == 0 && grid[row][col] == 2){
            finalAns++;
            return ;
        }

        // Mark Visited
        int temp = grid[row][col];
        grid[row][col] = 7 ;

        // DOWN --> row = row + 1 
        if(row+1 < grid.size()){
            if(grid[row+1][col] == 0){
                getUniquePaths(grid , row+1 , col , zeroCount-1 , finalAns);
            }
            if(grid[row+1][col] == 2){
                getUniquePaths(grid , row+1 , col , zeroCount , finalAns);
            }
        }

        // UP --> row = row - 1
        if(row - 1 >= 0 ){
            if(grid[row -1][col] == 0){
                getUniquePaths(grid , row-1 , col , zeroCount-1 , finalAns);
            }
            if(grid[row-1][col] == 2){
                getUniquePaths(grid , row-1 , col , zeroCount , finalAns);
            }
        }

        // RIGHT --> col = col + 1
        if(col + 1 < grid[0].size()){
            if(grid[row][col+1] == 0){
                getUniquePaths(grid , row , col+1 , zeroCount-1 , finalAns);
            }
            if(grid[row][col+1] == 2){
                getUniquePaths(grid , row , col+1 , zeroCount , finalAns);
            }
        }

        // LEFT --> col = col - 1
        if(col - 1 >= 0){
            if(grid[row][col-1] == 0){
                getUniquePaths(grid , row , col-1 , zeroCount-1 , finalAns);
            }
            if(grid[row][col-1] == 2){
                getUniquePaths(grid , row , col-1 , zeroCount , finalAns);
            }
        }

        grid[row][col] = temp ;
     }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size() ;
        int col = grid[0].size() ;

        int zeroCount = 0 ;
        int finalAns = 0 ;

        int startRow , startCol ;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 0) zeroCount++;
                if(grid[i][j] == 1){
                    startRow = i ;
                    startCol = j ;
                }
            }
        }

        getUniquePaths(grid, startRow, startCol, zeroCount, finalAns);
        return finalAns ;
    }
};