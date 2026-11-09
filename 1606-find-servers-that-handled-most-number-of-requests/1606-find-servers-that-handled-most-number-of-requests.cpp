class Solution {
public:
    typedef pair<int , int> P ;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers ;

        for(int i = 0 ; i < k ; i++){
            available_servers.insert(i);
        }

        priority_queue<P, vector<P> , greater<P>> busyServer ; // {finishTime , serverId}

        vector<int> countRequest(k , 0);

        for(int i = 0 ; i < arrival.size(); i++){
            int arrivalTime = arrival[i];

            while(!busyServer.empty() && busyServer.top().first <= arrivalTime){ // this server is now available
                int server = busyServer.top().second;
                busyServer.pop();

                available_servers.insert(server);
            } 


            int target = i % k ;

            auto it = available_servers.lower_bound(target);

            // Wrap around if no server >= target is available
            if(it == available_servers.end()){ 
                it = available_servers.begin();
            }

            // Drop request if no server is available
            if(available_servers.empty()) {
                continue;
            }

            int targetServer = *it ; // value at it

            // now this server will be busy --> erase from available
            available_servers.erase(it); 

            // push this in busy server 
            busyServer.push({arrivalTime + load[i] , targetServer});

            // targetServer is used one more time
            countRequest[targetServer]++;
        }

        int maxNumberOfRequests = *max_element(countRequest.begin() , countRequest.end());

        // now we have to return which server is used most of the time, not it's freq
        // we can also have multiple with same max freq

        vector<int> result ;

        for(int i = 0 ; i < k ; i++){ 
            if(countRequest[i] == maxNumberOfRequests){
                result.push_back(i);
            }
        }

        return result;
    }
};