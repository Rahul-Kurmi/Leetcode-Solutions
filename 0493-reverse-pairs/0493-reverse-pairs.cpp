class Solution {
public:

    void merge(vector<int>& nums, int start, int mid, int end, vector<int>& temp) {
        int left = start;
        int right = mid + 1;
        int k = start;

        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }

        while(left <= mid) temp[k++] = nums[left++];
        while(right <= end) temp[k++] = nums[right++];

        for(int i = start; i <= end; i++){
            nums[i] = temp[i];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end, vector<int>& temp, int& reverseCount){

        if(start >= end) return;

        int mid = start + (end - start)/2;

        mergeSort(nums, start, mid, temp, reverseCount);
        mergeSort(nums, mid+1, end, temp, reverseCount);

        // count reverse pairs
        int j = mid + 1;
        for(int i = start; i <= mid; i++){
            while(j <= end && (long long)nums[i] > (long long)2 * nums[j]){
                j++;
            }
            reverseCount += j - (mid + 1);
        }

        merge(nums, start, mid, end, temp);
    }

    int reversePairs(vector<int>& nums) {

        vector<int> temp(nums.size());
        int reverseCount = 0;

        mergeSort(nums, 0, nums.size()-1, temp, reverseCount);

        return reverseCount;
    }
};