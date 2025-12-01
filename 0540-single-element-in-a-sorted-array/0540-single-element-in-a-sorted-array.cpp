class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0 ;
        int end = nums.size() - 1;
        while(start <= end){
            if(start == end) return nums[start];
            int mid = start + (end - start) / 2 ;
            if(mid % 2 == 0 && mid + 1 < nums.size()){
                if(nums[mid] == nums[mid + 1] && mid + 2 < nums.size()){
                    start = mid + 2 ;
                }else{
                    end = mid ;
                }
            }
            else if(mid % 2 != 0 && mid + 1 < nums.size()){
                if(nums[mid] == nums[mid +1]){
                    end = mid - 1; 
                }else{
                    start = mid + 1;
                }
            }
        }
        return -1 ;
    }
};