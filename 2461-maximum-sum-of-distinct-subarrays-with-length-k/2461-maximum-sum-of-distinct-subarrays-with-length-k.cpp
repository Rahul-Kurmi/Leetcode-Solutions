class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n = arr.size() ;
        long long currSum = 0 ;
        long long maxSum = 0;
        unordered_map<int , int> mp ;

        // First Window
        for(int i = 0 ; i < k ; i++){
            currSum += arr[i];
            mp[arr[i]]++;
        }

        // If all unique elemnt in first window --> mp.size() == k
        if(mp.size() == k) maxSum = currSum ;

        // sliding window
        for(int i = k ; i < arr.size() ; i++){
            // add new element 
            mp[arr[i]]++;
            currSum += arr[i];

            // remove old element 
            mp[arr[i-k]]--;
            currSum -= arr[i-k];

            // if mp[arr[i-k]] == 0 --> still in map wrase it only if 0
            if(mp[arr[i-k]] == 0){
                mp.erase(arr[i-k]);
            }

            // check valid window
            if(mp.size() == k){
                maxSum = max(currSum , maxSum);
            }
        }
        return maxSum;
    }
};