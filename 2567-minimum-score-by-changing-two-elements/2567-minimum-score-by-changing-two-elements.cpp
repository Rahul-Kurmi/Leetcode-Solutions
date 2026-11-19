class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0 ;

        sort(nums.begin() , nums.end());

        int possible1 = nums[n-1] - nums[2];
        int possible2 = nums[n-3] - nums[0];
        int possible3 = nums[n-2] - nums[1];


        int result = min({possible1, possible2, possible3});

        return result;
    }

};