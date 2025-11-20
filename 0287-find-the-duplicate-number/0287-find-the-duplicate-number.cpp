class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[0] == nums[nums[0]]) return nums[0];

            swap(nums[0] , nums[nums[0]]);
        }
        return -1 ;
    }
};