//Approach (2 Max Heaps)
//T.C : O((n+m)*logn)
//S.C : O(n)

class Solution {
public:
    typedef pair<int, int> P ;
    typedef tuple<long , int , int> T ;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // min-heap for free servers --> less weight server on top, if same then idx
        priority_queue<P , vector<P> , greater<P>> freeServers; // {wt , idx}

        // Busy servers {freeTime, wt, idx}
        // we need freeTime --> when will be the server free, also before new task check if any server are getting freed
        // wt , time --> we need this to push back in freeServers heap when this server is freed
        priority_queue<T , vector<T> , greater<T>> busyServers;

        // insert all the servers with {wt , idx}
        for(int i = 0; i < n; i++) { //n
            freeServers.push({servers[i], i}); //log(n)
        }

        vector<int> result(m) ; // this will give us the server used for a task

        for(int i = 0 ; i < m ; i++){
            // check if any server got free 
            // Move busy servers to free servers if they are free by ith time
            //Busy Servers ---> Free Servers
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i){
                auto [freeTime , wt , idx] = busyServers.top();
                busyServers.pop();
                // insert into free servers
                freeServers.push({wt, idx});
            }

            // now push server from freeServers ----> busyServers 
            // for the currebt task 

            if(freeServers.empty()){ // we don't have any server free
                // we must wait for the server from busyServers to get freed
                // and that server will be assigned this task
                auto [freeTime, wt, idx] = busyServers.top();
                busyServers.pop();

                // now this server freeTime --> intialFreeTime(of rev task) + tasks[i] (curr Task time)
                busyServers.push({freeTime + tasks[i] , wt, idx});

                // store result --> ie this server was assigned to this task
                result[i] = idx ;
            } 
            else{ // we have a free server present --> we can use that 
                auto [wt , idx] = freeServers.top() ;
                freeServers.pop();

                //insert this to busy server, freeTime = i + tasks[i] as at ith time we reached to this task
                busyServers.push({i + tasks[i] , wt , idx});

                result[i] = idx ;
            }
        }

        return result ;
    }
};