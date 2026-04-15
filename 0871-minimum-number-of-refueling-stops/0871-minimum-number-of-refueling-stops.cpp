class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0 ;
        int dist = 0 ;
        int i = 0 ;
        int fuel = startFuel ;
        priority_queue<pair<int, int>> pq ; // {fuel , position}
        while(true){
            while(i < stations.size()){
                // push stations within the reach with my current fule level from my current position
                if(stations[i][0] <= dist + fuel){
                    pq.push({stations[i][1], stations[i][0]});
                }
                else{
                    break; // can't travel at this position with this much fuel
                }
                i++;
            }

            // first travel with the full fuel level
            dist += fuel ;
            fuel = 0;

            // if reached 
            if(dist >= target) break ;

            // if no fuel stations within reach
            if(pq.empty()){
                stops = -1 ;
                break; 
            }         

            // re-fuel and re-adjust dist and fuel based on the distance travelled and fuel used till that station
            auto& top = pq.top();
            fuel = (dist - top.second) + top.first ; // Rem + curr Station fuel
            dist = top.second ; // so if refilled then we have reached here --> update dist
            pq.pop();
            stops++;    
        }
        return stops ;
    }
};