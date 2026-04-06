class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = nums.size() ;
        int findOne = -1 ;
        int findTwo = -1 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                findOne = i ;
                if(findTwo != -1){
                    ans = min(ans , abs(findOne - findTwo));
                }
            }
            if(nums[i] == 2){
                findTwo = i ;
                if(findOne != -1){
                    ans = min(ans , abs(findOne - findTwo));
                }
            }
        }
        return ans == nums.size() ? -1 : ans;
    }
};