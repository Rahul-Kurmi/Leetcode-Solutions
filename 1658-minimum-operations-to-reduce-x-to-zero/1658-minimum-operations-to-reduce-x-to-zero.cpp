//Using longest subarray Sum logic
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int, int> preSum ; // {preSum, index} --> we'll use index to get ans
        preSum[0] = -1 ; // if we want the prefixSum to be zero it will be at index -1

        int sum = 0;
        for(int i = 0 ; i < n; i++){
            sum += nums[i];
            preSum[sum] = i ;
        }

        if(sum < x){ // we can't remove x 
            return -1; 
        }

        int restSum = sum - x ;
        int longest = INT_MIN ;
        sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(preSum.count(sum - restSum)){ // means we're able to remove x
                longest = max(longest , i - preSum[sum - restSum]);
            }
        }

        return longest == INT_MIN ? -1 : n - longest ;
    }
};