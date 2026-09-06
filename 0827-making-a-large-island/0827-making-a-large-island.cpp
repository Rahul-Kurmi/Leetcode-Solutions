class Solution {
public:
    // DSU with findParent and Union with size of the set 
    int findParent(int x , vector<int>& parent){
        if(x == parent[x]){
            return x ;
        }

        return parent[x] = findParent(parent[x] , parent);
    }

    void unionBySize(int x, int y , vector<int>& size, vector<int>& parent){
        int parent_x = findParent(x , parent);
        int parent_y = findParent(y , parent);

        if(parent_x == parent_y) return ;

        if(size[parent_x] > size[parent_y]){
            parent[parent_y] = parent_x ;
            size[parent_x] += size[parent_y];
        }
        else{
            parent[parent_x] = parent_y ;
            size[parent_y] += size[parent_x];
        }
    }

    // Global directions array
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dsu_size = m * n ;
        vector<int> parent(dsu_size);
        for(int i = 0 ; i < dsu_size; i++){
            parent[i] = i ;
        }

        vector<int> size(dsu_size, 1);

        // Step 1: Connect all existing 1s using DSU
        // visit every 1 in grid all combine sets of 1 
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int curr_node = i * n + j  ; // curr_row * col size + curr_col
                    for(auto dir: directions){
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        // if this adj node is also 1 
                        if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && grid[new_i][new_j] == 1){
                            int new_node = new_i * n + new_j ; 
                            unionBySize(curr_node, new_node, size, parent);
                        }

                    }
                }
            }
        }


        // Step 2: Find the largest island without modification
        int maxArea = 0 ;
        for(int idx = 0 ; idx < dsu_size ; idx++){ // check for all DSU nodes which has maxArea
            // this below if is so that we do less iteration ie. only for cell with 1 
            if(grid[idx/m][idx%m] == 1){    // grid[idx/total_row][idx%total_row] --> gives correspoinding cell to node
                maxArea = max(maxArea , size[idx]);
            }
        }
        
        // Step 3: Try flipping each 0 to 1
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> uniqueParents;
                    for(auto dir: directions){
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        // if this adj node is also 1 
                        if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && grid[new_i][new_j] == 1){
                            int new_node = new_i * n + new_j ; 
                            uniqueParents.insert(findParent(new_node, parent));
                        }
                    }

                    int newSize = 1; // Flip this 0 to 1
                    for (int parent : uniqueParents) {
                        newSize += size[parent];
                    }
                    maxArea = max(maxArea, newSize);
                }
            }
        }
        return maxArea;
    }
};