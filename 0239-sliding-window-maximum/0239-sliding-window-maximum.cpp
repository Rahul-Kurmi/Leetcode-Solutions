class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i = 0 ; i < k ; i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i = 0 ; i < arr.size() - k + 1 ; i++){
            // remove out of window index
            if(dq.front() < i) dq.pop_front();

            // store answer
            ans.push_back(arr[dq.front()]);
            
            // add next element
            if(i + k < arr.size()){
                int val = arr[i+k];
                while(!dq.empty() && arr[dq.back()] <= val){
                    dq.pop_back();
                }

                dq.push_back(i+k);
            }
            
        }
        return ans ;
    }
};