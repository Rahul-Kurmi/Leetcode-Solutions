
class NodeData{
    public : 
        vector<int> data ;
        int dist;
        NodeData(vector<int> _d , int _dist) : data(_d) , dist(_dist) {};
};

class compare{
    public :
        bool operator()(NodeData* a , NodeData* b){
            return a -> dist < b -> dist ;
        }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<NodeData* , vector<NodeData*> , compare> maxHeap ;
        
        for(int i = 0 ; i < k ; i++){
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            maxHeap.push(new NodeData({points[i][0] , points[i][1]} , dist));
        }

        for(int i = k ; i < points.size() ; i++){
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            int topDist = maxHeap.top() -> dist ;
            if(dist < topDist){
                maxHeap.pop();
                maxHeap.push(new NodeData({points[i][0], points[i][1]}, dist));
            }
        }

        vector<vector<int>> ans ;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top() -> data);
            maxHeap.pop();
        }

        return ans;
    }
};