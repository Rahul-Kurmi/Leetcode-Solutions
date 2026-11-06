//Approach (Sorting + Sliding Window)
//T.C : O(nlogn + qlogq), n = log.size(), q = query.size()
//S.C : O(n + q)

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        // lambda to sort logs
        auto lambda = [](vector<int>& vec1 , vector<int>& vec2){
            return vec1[1] < vec2[1]; // sort on the basis of time
        };

        sort(logs.begin(), logs.end() , lambda);

        int q = queries.size();
        vector<int> result(q);

        vector<pair<int, int>> timeIndex(q);
        for(int i = 0 ; i < q ; i++){
            timeIndex[i] = {queries[i] , i};
        }

        // sort queries on the basis of time
        sort(timeIndex.begin() , timeIndex.end());

        // this map will store all the unique counts of server
        unordered_map<int, int> mp ;

        int i = 0 ;
        int j = 0;

        // iterarte of all the queries --> ie timeIndex
        for(auto [time , idx] : timeIndex){
            // range 
            int start = time - x;
            int end = time ;

            // Expansion 
            while(j < logs.size() && logs[j][1] <= end){ // <= end means all in left range 
                // store / increase current server count
                mp[logs[j][0]]++;
                j++;
            }  

            // shrinking Logic this removes all the requests that is not in range
            while(i < logs.size() && logs[i][1] < start){ // < start means all out of range
                mp[logs[i][0]]--;
                // if this server is removed then remove it's key from map
                // as we will use this map's size to get our result 
                if(mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }

                i++;
            }


            // get all the servers that is not in the range
            // as : mp.size() = # of serveres getting request in [start , end]
            
            // idx --> store ans in same query index
            result[idx] = n - mp.size(); 
        }

        return result ;
    }
};