class Solution {
public:
    
    bool checkIfExist(vector<vector<char>>& board , string& word ,
                      int row , int col, int wordCount, vector<vector<bool>>& isVisited){
        
        if(wordCount == word.size()){
            return true ;
        }

        isVisited[row][col] = true ;

        int rows = board.size();
        int cols = board[0].size();

        // DOWN
        if(row+1 < rows && board[row+1][col] == word[wordCount] && (!isVisited[row+1][col])) {
            if(checkIfExist(board , word, row+1 , col , wordCount+1, isVisited))
                return true;
        }

        // UP
        if(row-1 >= 0 && board[row-1][col] == word[wordCount] && (!isVisited[row-1][col])) {
            if(checkIfExist(board , word, row-1 , col , wordCount+1, isVisited))
                return true;
        }

        // LEFT
        if(col-1 >= 0 && board[row][col-1] == word[wordCount] && (!isVisited[row][col-1])) {
            if(checkIfExist(board , word, row , col-1 , wordCount+1, isVisited))
                return true;
        }

        // RIGHT
        if(col+1 < cols && board[row][col+1] == word[wordCount] && (!isVisited[row][col+1])) {
            if(checkIfExist(board , word, row , col+1 , wordCount+1, isVisited))
                return true;
        }

        isVisited[row][col] = false ;  // restore
        return false ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> isVisited(row , vector<bool>(col , false));

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == word[0] &&
                   checkIfExist(board , word, i , j , 1, isVisited)){
                    return true ;
                }
            }
        }
        return false ;
    }
};