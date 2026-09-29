//T.C : O(m*n*(m+n))
//S.C : O(m*n*(m+n))
class Solution {
public:
    int m, n;
    bool t[101][101][201];

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1) % 2 == 1)
            return false;

        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') {
            return false;
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                for(int openCount = 0; openCount <= i+j+1; openCount++) {
                    if(i == m-1 && j == n-1) {
                        t[i][j][openCount] = (openCount == 0);
                        continue;
                    }

                    t[i][j][openCount] = false;

                    //mode down
                    if(i+1 < m) {
                        int newOpCount = (grid[i+1][j] == '(') ? openCount + 1 : openCount-1;
                        if(newOpCount >= 0 && t[i+1][j][newOpCount] == true) {
                            t[i][j][openCount] = true;
                        }
                    }

                    //mode right
                    if(j+1 < n) {
                        int newOpCount = (grid[i][j+1] == '(') ? openCount + 1 : openCount-1;
                        if(newOpCount >= 0 && t[i][j+1][newOpCount] == true) {
                            t[i][j][openCount] = true;
                        }
                    }

                }

            }
        }

        return t[0][0][1];

        
    }
};


// At cell (i, j):
//
// We have covered (i + 1) rows:
//     rows 0, 1, 2, ..., i
//
// We have covered (j + 1) columns:
//     columns 0, 1, 2, ..., j
//
// But along a path, we do NOT visit all cells in these rows/columns.
// We only visit one cell at each step.
//
// Number of cells visited from (0,0) to (i,j):
//     i DOWN moves + j RIGHT moves + 1 starting cell
//     = i + j + 1
//
// Therefore, maximum possible openCount is i + j + 1.


// for(int openCount = 0; openCount <= i+j+1; openCount++) 