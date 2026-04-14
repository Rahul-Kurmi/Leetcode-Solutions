class NodeData{
    public :
        int data ;
        int index ;
        NodeData(int _d , int _i) : data(_d) , index(_i) {};
};

class compare{
    public :
        bool operator()(NodeData*& a , NodeData*& b ){
            return a -> data < b -> data ;
        }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<NodeData* , vector<NodeData*> , compare> maxHeap;

        for(int i = 0 ; i < k ; i++){
            maxHeap.push(new NodeData(nums[i] , i));
        }

        ans.push_back(maxHeap.top() -> data);

        for(int i = k ; i < nums.size() ; i++){
            while(!maxHeap.empty() && maxHeap.top() -> index <= i - k ) maxHeap.pop() ;
            maxHeap.push(new NodeData(nums[i] , i));
            ans.push_back(maxHeap.top() -> data);
        }

        return ans ;
    }
};