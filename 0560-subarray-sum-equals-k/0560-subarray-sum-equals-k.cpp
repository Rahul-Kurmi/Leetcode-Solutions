class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp ;
        
        int preSum = 0 ;
        int count = 0 ;

        for(int i = 0 ; i < n ; i++){
            preSum += nums[i];

            if(preSum == k) count++;

            int diff = preSum - k ;

            if(mp.find(diff) != mp.end()){
                count += mp[diff];
            }

            mp[preSum]++;
        }

        return count ;
    }
};