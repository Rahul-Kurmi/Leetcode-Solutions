class Solution {
public:
    void merge(vector<int>&arr, int start , int end){
        int size = end - start + 1 ;
        int gap = size / 2 + size % 2 ;
        while(gap > 0){
            int i = start ;
            int j = start + gap ;
            while(j <= end){
                if(arr[i] > arr[j]){
                    swap(arr[i] , arr[j]);
                }
                i++;
                j++;
            }
            gap = (gap == 1) ? 0 : (gap / 2) + (gap % 2) ;
        } 
    }

    void mergeSort(vector<int>&arr, int start , int end){
        if(start >= end) return ;
        
        int mid = start + (end - start) / 2 ;

        mergeSort(arr,  start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end);

    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size() - 1);
        return nums ;
    }
};