class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push(nums[i]);
        }
        if(k != 0)
            k = k - 1 ;
        while(k--){
            pq.pop();
        }
        
        return pq.top();
    }
};