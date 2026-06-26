class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int , int> mp ; // preSum --> count 

        int preSum = 0;
        mp[0] = 1 ;

        long long validLeftPoints = 0 ;
        long long result = 0;

        for(int j = 0 ; j < nums.size(); j++){
            if(nums[j] == target){
                validLeftPoints += mp[preSum];
                preSum += 1 ;
            }
            else{
                preSum -= 1 ;
                validLeftPoints -= mp[preSum];
            }

            mp[preSum] += 1;
            result += validLeftPoints ; 
        }

        return result ;
    } 
};