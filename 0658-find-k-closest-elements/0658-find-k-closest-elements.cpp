class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int pos = it - arr.begin();
        
        int left = pos - 1;
        int right = pos;
        vector<int> ans;
        
        while(k > 0){
            int leftDiff = (left >= 0) ? abs(x - arr[left]) : INT_MAX;
            int rightDiff = (right < arr.size()) ? abs(x - arr[right]) : INT_MAX;
            
            if(leftDiff <= rightDiff){
                ans.push_back(arr[left]);
                left--;
            }
            else{
                ans.push_back(arr[right]);
                right++;
            }
            k--;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};