class Solution {
public:

    int MOD = 1e9 + 7 ;

    long long modPower(long long base, long long exp) {
        long long ans = 1;

        while(exp > 0) {

            if(exp & 1) {          // exponent is odd ie. exp = 1 --> base is ans ie. 1*base
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;            // exp /= 2
        }

        return ans;
    }

    
    int maxHeightCalculate(unordered_map<int, vector<int>>& adjElements , int root , int parent){

        int maxHeight = 0 ;

        for(int neighbour : adjElements[root]){
            if(neighbour == parent) continue ;

            maxHeight = max(maxHeight , maxHeightCalculate(adjElements, neighbour, root) + 1);
        }

        return maxHeight ;
    }


    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjElements ;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adjElements[u].push_back(v);
            adjElements[v].push_back(u);
        }

        int maxHeight = maxHeightCalculate(adjElements , 1 , -1);

        int oddPossibility = modPower(2, maxHeight - 1);

        return oddPossibility;
    }
};