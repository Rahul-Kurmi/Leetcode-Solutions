class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int i = 0 ;
        int j = 1 ;
        int k = 1 ;
        int count = 0 ;
        while(k < nums.size()){
            if(nums[i] == nums[k]){
                k++;
                count++;
            }else{
                nums[j] = nums[k];
                i = j ;
                k++;
                j++;
            }
        }
        
         while (count > 0) {
            nums.pop_back();
            count--;
         }

        return nums.size();
    }
};