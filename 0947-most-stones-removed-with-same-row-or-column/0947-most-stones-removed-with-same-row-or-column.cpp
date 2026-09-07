class Solution {
public:
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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0; 
        int maxCol = 0;

        for(auto stone : stones){
            maxRow = max(maxRow , stone[0]);
            maxCol = max(maxCol , stone[1]);
        }

        // DSU total Nodes = maxRow + maxCol
        int dsu_nodes = maxRow + maxCol + 2; 
        vector<int> parent(dsu_nodes);
        for(int i = 0 ; i < dsu_nodes; i++){
            parent[i] = i ;
        }

        vector<int> size(dsu_nodes, 1);

        unordered_map<int, int> stoneNodes ;

        for(auto stone : stones){
            int nodeRow = stone[0];
            int nodeCol = stone[1] + maxRow + 1 ; 
            // col Node = col + totalRow ie. (maxRow + 1)

            unionBySize(nodeRow, nodeCol, size, parent);
            stoneNodes[nodeRow] = 1 ;
            stoneNodes[nodeCol] = 1 ; 
        }


        int cnt = 0;
        for(auto it: stoneNodes){
            if(findParent(it.first , parent) == it.first){
                cnt++;
            }
        }

        return n - cnt ;
    }
};