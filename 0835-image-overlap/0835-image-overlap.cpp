class Solution {
public:
    int countOverLaps(vector<vector<int>>& A, vector<vector<int>>& B, int row_offset, int col_offset){
        int n = A.size() ;

        int count = 0 ;
        // iterate on A 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                // find indices of A from indices of A
                /*
                    A[i][j] --> B[i + row_offset][j + col_offset]
                */

                int B_i = i + row_offset ;
                int B_j = j + col_offset ;

                // check for invalid indices 
                if(B_i < 0 || B_j < 0 || B_i >= n || B_j >= n) continue  ;

                if(A[i][j] == 1 && B[B_i][B_j] == 1) count++;
            }
        }

        return count ;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size() ;
        // n * n matrix, row = col = n

        int maxOverLaps = 0 ;
        for(int row_offset = -n+1 ; row_offset < n ; row_offset++){
            for(int col_offset = -n+1 ; col_offset < n ; col_offset++){
                int count = countOverLaps(A, B , row_offset , col_offset);

                maxOverLaps = max(count , maxOverLaps);
            }
        }

        return maxOverLaps;
    }
};