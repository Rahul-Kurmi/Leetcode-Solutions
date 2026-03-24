class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int iterateZero = 0;
        int index = 0 ;
        while(iterateZero < nums.size()){
            if(nums[iterateZero] == 0) iterateZero++;
            else{
                swap(nums[index] , nums[iterateZero]);
                iterateZero++;
                index++;
            }
        }
    }
};