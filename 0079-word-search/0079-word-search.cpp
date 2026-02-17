class Solution {
public:
    
    bool checkIfExist(vector<vector<char>>& board , string& word ,
                      int row , int col, int wordCount){
        
        if(wordCount == word.size()){
            return true ;
        }

        char temp = board[row][col];
        board[row][col] = '#';  // mark visited

        int rows = board.size();
        int cols = board[0].size();

        // DOWN
        if(row+1 < rows && board[row+1][col] == word[wordCount]) {
            if(checkIfExist(board , word, row+1 , col , wordCount+1))
                return true;
        }

        // UP
        if(row-1 >= 0 && board[row-1][col] == word[wordCount]) {
            if(checkIfExist(board , word, row-1 , col , wordCount+1))
                return true;
        }

        // LEFT
        if(col-1 >= 0 && board[row][col-1] == word[wordCount]) {
            if(checkIfExist(board , word, row , col-1 , wordCount+1))
                return true;
        }

        // RIGHT
        if(col+1 < cols && board[row][col+1] == word[wordCount]) {
            if(checkIfExist(board , word, row , col+1 , wordCount+1))
                return true;
        }

        board[row][col] = temp;  // restore
        return false ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == word[0] &&
                   checkIfExist(board , word, i , j , 1)){
                    return true ;
                }
            }
        }
        return false ;
    }
};
