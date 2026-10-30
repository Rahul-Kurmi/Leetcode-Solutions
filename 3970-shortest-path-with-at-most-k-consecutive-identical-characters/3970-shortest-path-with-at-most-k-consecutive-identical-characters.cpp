class Solution {
public:
    //Appoach Using Dijkstra's
    //Let V = n, E = edges.length, k = max count length, usually Dijkstra is O(E * log(V)), in this problem, E = E*K and V = n*K
    //T.C : O(E*K * log(n*K))
    //S.C : O(V+E) = O(n*K + E*k)

    typedef tuple<int ,int, int> T ;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // create adjList 
        unordered_map<int , vector<vector<int>>> adjList ;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adjList[u].push_back({v, wt});
        }

        // distance or result vector
        vector<vector<int>> result(n, vector<int>(k+1 , INT_MAX));

        // creating priority queue(minHeap) for diakstra
        // storing value --> {weight , node, count}

        priority_queue<T , vector<T> , greater<T>> pq ; // min heap

        result[0][1] = 0 ; // to reach src = 0 count = 1

        pq.push({0 , 0 , 1}) ; // to reach src from src -> wt = 0, reachedNode = 0, count = 0   

        while(!pq.empty()){
            auto [dist, node, count] = pq.top();
            pq.pop();

            // we already got better way
            if(dist > result[node][count]){
                continue ;
            }

            // reached the target 
            if(node == n-1){
                return dist ;
            }

            for(auto& ngh : adjList[node]){
                int adjNode = ngh[0];
                int adjWt = ngh[1];
                
                // check for cosecutive characters
                // if adjNodeChar == currNodeChar --> +1 count
                // else not same --> start cosecutive char count for adjNode as 1 
                int newCount = (labels[node] == labels[adjNode]) ? count + 1 : 1 ; 
                
                if(newCount > k){ // means this can-not be a valid ans
                    continue ; 
                }

                int newDist = dist + adjWt;

                // we got better solution
                if(newDist < result[adjNode][newCount]){
                    result[adjNode][newCount] = newDist ;
                    // insert this entry in minHeap
                    pq.push({newDist , adjNode, newCount});
                }
            }
        }
        return -1 ;
    }
};