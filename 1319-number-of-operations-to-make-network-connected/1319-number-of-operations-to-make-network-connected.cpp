class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = true;

        for(auto& neighbour : adjList[node]) {
            if(!visited[neighbour]) {
                dfs(neighbour, adjList, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges = connections.size();

        // If there are n nodes, at least n-1 edges are required
        // to connect all the nodes.
        // If we have fewer than n-1 edges, it is impossible
        // to make all the nodes connected.
        if(totalEdges < n - 1) return -1;

        // Since we have at least n-1 edges, it is possible to
        // connect all the nodes.
        // Now, we find the number of disconnected components.
        // To connect 'components' components, we need
        // exactly 'components - 1' connections.
        
        vector<vector<int>> adjList(n);

        for(auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int components = 0;

        // Count the number of disconnected components.
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adjList, visited);
                components++;
            }
        }

        // To connect 'components' components,
        // we need 'components - 1' connections.
        return components - 1;
    }
};