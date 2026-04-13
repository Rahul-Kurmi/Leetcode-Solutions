class Solution {
public:
    class myComp{
        public :
            bool operator()(pair<int, int>&a , pair<int , int>& b){
                int distA = a.first*a.first + a.second*a.second;
                int distB = b.first*b.first + b.second*b.second;
                return distA > distB ;
            }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int> , vector<pair<int, int>> , myComp> minHeap ;

        for(auto pt : points){
            minHeap.push({pt[0] , pt[1]});
        }

        vector<vector<int>> ans ;
        while(!minHeap.empty() && k--){
            auto& top = minHeap.top();
            ans.push_back({top.first , top.second}); 
            minHeap.pop();
        }

        return ans;   
    }
};