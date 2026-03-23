class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum += mat[i][i];
        }

        int i = 0 ;
        int j = n - 1;
        while(i < n){
            sum += mat[i][j];
            i++;
            j--;
        } 

        if(n % 2){
            int midIndex = n / 2 ;
            sum -= mat[midIndex][midIndex];
        }

        return sum ;
    }
};