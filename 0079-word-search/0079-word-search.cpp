class Solution {
public:
    
    void  checkIfExist(vector<vector<char>>& board , string& word ,
                      int row , int col, int wordCount , bool& ans ){
        
        if(wordCount == word.size()){
            ans = true ;
            return;
        }

        char temp = board[row][col];
        board[row][col] = '#';  // mark visited

        int rows = board.size();
        int cols = board[0].size();

        // DOWN
        if(row+1 < rows && board[row+1][col] == word[wordCount]) {
            checkIfExist(board , word, row+1 , col , wordCount+1 , ans );
        }

        // UP
        if(row-1 >= 0 && board[row-1][col] == word[wordCount]) {
           checkIfExist(board , word, row-1 , col , wordCount+1, ans);
        }

        // LEFT
        if(col-1 >= 0 && board[row][col-1] == word[wordCount]) {
            checkIfExist(board , word, row , col-1 , wordCount+1, ans);
        }

        // RIGHT
        if(col+1 < cols && board[row][col+1] == word[wordCount]) {
            checkIfExist(board , word, row , col+1 , wordCount+1, ans);
        }

        board[row][col] = temp;  // restore;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        bool ans = false ;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == word[0]){
                    checkIfExist(board , word, i , j , 1, ans);
                }
            }
        }
        return ans ;
    }
};