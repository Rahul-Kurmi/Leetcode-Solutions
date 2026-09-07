class Solution {
public:
    // DFS call, marking all the related stones visied and increasing count by 1 
    // this helps us find no. of sets of related stones 

    void dfs(int i, vector<vector<int>>& stones, vector<int>& visited){
        visited[i] = 1 ;

        for(int j = 0 ; j < stones.size(); j++){
            if(!visited[j]){
                // if any of row or col matches
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    dfs(j , stones, visited);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n , 0);

        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i , stones, visited);
                count++;
            }
        }

        return n - count ;
    }
};