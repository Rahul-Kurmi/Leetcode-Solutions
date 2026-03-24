class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int iterateZero = 0;
        int index = 0 ;
        while(iterateZero < nums.size()){
            if(nums[iterateZero] == 0) iterateZero++;
            else{
                // Here we placed all the non zeros in right side
                // but this is copy of all non zeros  
                nums[index] = nums[iterateZero];
                iterateZero++;
                index++;
            }
        }

        // After index we have to make all zeros
        while(index < nums.size()) {
            nums[index++] = 0 ;
        }
    }
};