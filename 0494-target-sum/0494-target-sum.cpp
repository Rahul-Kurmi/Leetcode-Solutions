class Solution {
public:
    void findSolution(vector<int>& nums , int i , int& target , int& count, int sum){
        if(i == nums.size()){
            if(sum == target){
                count++;
            }
            return;
        }

        int positiveSum = sum + nums[i];
        int negativeSum = sum + (-nums[i]);
        i++;
        findSolution(nums , i  , target , count , positiveSum);
        findSolution(nums , i  , target , count , negativeSum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       int count = 0 ;
       findSolution(nums , 0 ,target , count , 0); 
       return count ;
    }
};