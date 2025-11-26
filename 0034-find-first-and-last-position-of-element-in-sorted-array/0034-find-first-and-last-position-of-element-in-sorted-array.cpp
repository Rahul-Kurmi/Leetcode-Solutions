class Solution {
public:
    int binarySearch(vector<int>& arr , int target){
        int low = 0 ;
        int high = arr.size() - 1;
        int mid = low + (high - low)/2 ;
        while(low <= high){
            if(arr[mid] == target){
                return mid;
            }
            else if(target > arr[mid]){
                low = mid + 1 ;
            }
            else{
                high = mid - 1 ;
            }
            mid = low + (high - low) / 2 ;
        }
        return -1; ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1 , -1} ;
        int index = binarySearch(nums , target);
        if(index == -1 ) return {-1 , -1} ; 
        int i = index ;
        int j = index ;
        int low , high ;
        while(i >= 0 && nums[i] == nums[index]){
                low = i ;
                i--;
        }
        while(j < nums.size() && nums[j] == nums[index]){
                high = j ;
                j++;
        }

        return {low , high} ;
    }
};