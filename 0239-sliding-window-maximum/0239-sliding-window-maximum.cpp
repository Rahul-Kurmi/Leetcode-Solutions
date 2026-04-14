class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans ;
        priority_queue<pair<int, int>> maxHeap;

        // condider first k elements 
        for(int i = 0 ; i < k ; i++){
            maxHeap.push({nums[i] , i});
        }

        //store max for first window 
        ans.push_back(maxHeap.top().first);

        //consider rest of the window
        for(int i = k ; i < nums.size() ; i++){
            // push current elemnet
            maxHeap.push({nums[i] , i});

            //remove all the max elements not in this window
            while(maxHeap.top().second <= i - k){
                maxHeap.pop();
            }

            // store max for current window
            ans.push_back(maxHeap.top().first);
        }
        return ans ;
    }
};