class NodeData{
    public :
        int data ;
        int row ;
        int col;

        NodeData(int d , int r , int c){
            data = d ;
            row = r ;
            col = c ;
        }
};

class compare{
    public : 
    bool operator () (NodeData* a , NodeData* b){
        return a -> data > b -> data ; 
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = nums[0][0] ;
        int maxi = nums[0][0] ;
        
        priority_queue<NodeData* ,vector<NodeData*> , compare > minHeap ;
        int k = nums.size();
        for(int i = 0;i<k;i++){
            int element = nums[i][0];
            maxi = max(maxi,element);
            mini = min(mini,element);
            minHeap.push(new NodeData(element,i,0));
        }

        int ansStart = mini ;
        int ansEnd = maxi ;

        while(!minHeap.empty()){
            NodeData * top = minHeap.top() ;
            int topElement = top -> data ;
            int topRow = top -> row ;
            int topCol = top -> col ;
            minHeap.pop();

            // mini updated 
            mini = topElement ;

            // Range updated 
            // Check for ans
            int currRange = maxi - mini ;
            int ansRange = ansEnd - ansStart ;
            if(currRange < ansRange){
                ansStart = mini ;
                ansEnd = maxi ;
            }

            // check for new element in the same list 
            if(topCol + 1 < nums[topRow].size()){
                maxi = max(maxi , nums[topRow][topCol + 1] ) ;
                NodeData * newHeapData = new NodeData (nums[topRow][topCol + 1] , topRow , topCol + 1 ) ;
                minHeap.push(newHeapData) ;
            }
            else{
                // there is no element in the same array or list --> found our range 
                break ;
            }
        }
    
        return {ansStart , ansEnd} ;
    }
};