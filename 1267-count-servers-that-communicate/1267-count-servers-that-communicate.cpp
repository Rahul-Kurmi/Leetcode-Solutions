// Approach 4 : DSU
class Solution {
public:
    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {

        int x_parent = findParent(x, parent);
        int y_parent = findParent(y, parent);

        if(x_parent == y_parent) return;

        if(rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        }
        else if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int findParent(int x, vector<int>& parent) {
        if(x == parent[x]) {
            return x;
        }

        return parent[x] = findParent(parent[x], parent);
    }

    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // DSU contains row nodes + column nodes
        vector<int> parent(m + n);
        vector<int> rank(m + n, 0);

        for(int i = 0; i < m + n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> adjList(m);

        // Build adjacency list
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    adjList[i].push_back(m + j);

                    // Connect row i with column m+j
                    Union(i, m + j, parent, rank);
                }
            }
        }

        // Count actual servers in each connected component
        unordered_map<int, int> mp;

        for(int i = 0; i < m; i++) {
            for(auto ngh : adjList[i]) {

                int root = findParent(i, parent);
                mp[root]++;
            }
        }

        // Count servers belonging to components with size > 1
        int ans = 0;

        for(auto &it : mp) {
            if(it.second > 1) {
                ans += it.second;
            }
        }

        return ans;
    }
};