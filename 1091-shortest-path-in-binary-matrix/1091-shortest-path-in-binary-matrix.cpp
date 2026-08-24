class Solution {
public:
    // USING Dijkstra but using queue --> why?
    // Because every edge/move has weight = 1.
    
    vector<vector<int>> directions = {
        {0,-1}, {-1,0}, {1,0}, {0,1},
        {1,-1}, {-1,1}, {1,1}, {-1,-1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!q.empty()){
            
            int currDist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            
            q.pop();

            for(auto& dir : directions){
                
                int moveX = x + dir[0];
                int moveY = y + dir[1];

                if(moveX >= 0 && moveX < m &&
                   moveY >= 0 && moveY < n &&
                   grid[moveX][moveY] == 0){

                    if(currDist + 1 < dist[moveX][moveY]){
                        
                        dist[moveX][moveY] = currDist + 1;
                        
                        q.push({
                            dist[moveX][moveY],
                            {moveX, moveY}
                        });
                    }
                }
            }
        }

        if(dist[m-1][n-1] == 1e9)
            return -1;

        return dist[m-1][n-1] + 1;
    }
};