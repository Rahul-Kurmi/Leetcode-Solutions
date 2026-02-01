class Solution {
public:

    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> bottomLeftDiagonalCheck;

    void storeAns(vector<vector<char>>& store  , vector<vector<string>>& ans){
        vector<string> temp;
        string val = "";
        for(int i = 0 ; i < store.size() ; i++){
            for(int j = 0 ; j < store.size() ; j++){
                val.push_back(store[i][j]);
            }
            temp.push_back(val);
            val = "";
        }
        ans.push_back(temp);
        
    }

    bool isSafe(vector<vector<char>>& store , int col , int row){
       if(rowCheck[row]){
        return false ;
       }
       if(upperLeftDiagonalCheck[store.size() + 1 + row - col]){
        return false ;
       }
       if(bottomLeftDiagonalCheck[row+col]){
        return false ;
       }

       return true ;
    }

    void solve(vector<vector<char>>& store , int n , int col ,  vector<vector<string>>& ans){
        if(col == n){
            storeAns(store , ans);
            return ;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(store, col , row)){
                rowCheck[row] = true ;
                upperLeftDiagonalCheck[store.size() + 1 + row - col] = true ;
                bottomLeftDiagonalCheck[row + col] = true ;

                store[row][col] = 'Q';
                solve(store , n , col+1, ans);
                store[row][col] = '.';

                rowCheck[row] = false ;
                upperLeftDiagonalCheck[store.size() + 1 + row - col] = false ;
                bottomLeftDiagonalCheck[row + col] = false ;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> store(n , vector<char>(n , '.'));
        vector<vector<string>> ans ;
        solve(store , n , 0 , ans);
        return ans;
    }

};