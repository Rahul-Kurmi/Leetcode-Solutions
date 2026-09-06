//Approach - 3  - Optimal DFS (You can use BFS as well)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m , n ;
    vector<vector<int>> directions = {{0,1} , {1,0} , {-1, 0}, {0, -1}};

    int DFS(int i , int j , vector<vector<int>>& grid, int unique_id){
        grid[i][j] = unique_id ;

        int size =  1;

        for(auto dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && grid[new_i][new_j] == 1){
                size += DFS(new_i , new_j , grid, unique_id);
            }
        }

        return size ; 
    }


    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        unordered_map<int , int> setUniqueIds ;
        int unique_id = 2 ; // starting with unique id = 2 

        int maxArea = 0 ;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int islandSize = DFS(i , j , grid, unique_id);
                    setUniqueIds[unique_id] = islandSize;
                    unique_id++;
                    maxArea = max(maxArea, islandSize);
                }
            }
        }

        

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                unordered_set<int> st; // store all unique ids
                if(grid[i][j] == 0){
                    for(vector<int>& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
                            st.insert(grid[x][y]);
                    }
                    
                    int sum = 1; //converting current 0 to 1
                    for(const int &s : st) {
                        sum += setUniqueIds[s];
                    }
                    maxArea = max(maxArea, sum);
                }
            }
        }

        return maxArea;
    }
};