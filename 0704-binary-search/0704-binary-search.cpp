class Solution {
public:
    int bs (vector<int>&nums , int low , int high , int target){
        int mid = low + (high - low) / 2 ;
        while(low <= high){
            if(nums[mid] == target){
                return mid ;
            }
            else if(target > nums[mid]){
                low = mid + 1 ;
            }else{
                high = mid - 1 ;
            }
            cout << mid << endl ;
            mid = low + (high - low) / 2 ;
        }

        return -1 ;
    }

    int search(vector<int>& nums, int target) {
       if(nums[0] == target) return 0 ;
       int i = 1 ;
       int n = nums.size();
       while(i < nums.size() && nums[i] <= target){
        i = i * 2;
       }
       int ans = bs(nums , i/2 , min(i , n-1), target);
       return ans ;
    }
};