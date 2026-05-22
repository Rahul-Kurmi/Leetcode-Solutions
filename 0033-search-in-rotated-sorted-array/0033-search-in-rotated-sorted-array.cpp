class Solution {
public:
    int findMinIndex(vector<int>& arr){
        int start = 0 ;
        int end = arr.size() - 1 ;
        while(start < end){
            int mid = start + (end - start) / 2 ;
            if(arr[mid] > arr[end]){
                start = mid + 1 ;
            }
            else{
                end = mid ;
            }
        }
        return start ;
    }

    int binarySearch(vector<int>& arr, int start , int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2 ;
            if(arr[mid] == target) return mid ;
            else if (arr[mid] > target) end = mid - 1;
            else start = mid + 1; 
        }
        return -1 ;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minIndex = findMinIndex(nums);
        int leftSearch = binarySearch(nums, 0 , minIndex-1 , target);
        int rightSearch = binarySearch(nums, minIndex, n-1 , target);

        return leftSearch == -1 ? rightSearch : leftSearch;
    
    }
};