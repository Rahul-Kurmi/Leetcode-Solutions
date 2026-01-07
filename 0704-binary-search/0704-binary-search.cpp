class Solution {
public:
    int BinarySearch(vector<int>& nums, int& target, int left, int right){
        if(left > right) return -1;
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target){
            return BinarySearch(nums, target, mid + 1, right); 
        }
        else{
            return BinarySearch(nums, target, left, mid - 1);  
        }
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int ans = BinarySearch(nums, target, 0, n);
        return ans; 
    }
};