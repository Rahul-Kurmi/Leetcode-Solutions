class Solution {
public:
    vector<vector<int>> directions = {{1, 0} , {-1,0} , {0, 1} , {0 , -1}};
    bool checkIfExist(vector<vector<char>>& board, string word, int row, int col, int iterate){
        if(iterate == word.size()) return true ;
        char temp = board[row][col];
        board[row][col] = '$' ;

        for(auto& dir : directions){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row >= 0 && new_row < board.size() && new_col >= 0 && new_col < board[0].size()){
                if(board[new_row][new_col] == word[iterate] && checkIfExist(board , word , new_row , new_col , iterate+1)){
                    return true ;
                }
            }
        }

        board[row][col] = temp ;
        return false ;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size() ;
        int col = board[0].size();

        int start = word[0] ;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == start && checkIfExist(board, word , i , j , 1)){
                    return true ;
                }
            }
        }
        return false ;
    }
};