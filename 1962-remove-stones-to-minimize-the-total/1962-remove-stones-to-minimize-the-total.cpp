class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap ;
        for(int i = 0 ; i < piles.size() ; i++ ){
            maxHeap.push(piles[i]);
        }

        while(k--){
            int maxElement = maxHeap.top();
            maxHeap.pop() ;
            maxElement = maxElement - (maxElement/2) ;
            maxHeap.push(maxElement) ;
        }

        int sum = 0 ;
        while(!maxHeap.empty()){
            int temp = maxHeap.top() ;
            maxHeap.pop() ;
            sum = sum + temp ;
        }

        return sum ;
    }
};