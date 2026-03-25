class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> rowColSumMap;
        int row = mat.size();
        int col = mat[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int rowColSum = i+j ;
                rowColSumMap[rowColSum].push_back(mat[i][j]);
            }
        }

        vector<int> ans ;
        bool flip = true ;
        for(auto ithDiagonal : rowColSumMap){
            if(flip){
                reverse(ithDiagonal.second.begin(), ithDiagonal.second.end());
            }
            for(auto it : ithDiagonal.second){
                ans.push_back(it);
            }
            flip = !flip ;
        }
        return ans ;
    }
};