class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int totalSum = 0 ;
        for(auto num : nums){
            totalSum += num ;
        }

        int leftSum = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum) return i ;
            leftSum += nums[i];
        }

        return -1 ;
    }
};