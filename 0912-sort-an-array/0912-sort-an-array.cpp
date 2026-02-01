class Solution {
public:
    void merge(vector<int> & arr , int s , int e){
        int mid = s + (e - s) / 2 ;
        vector<int> left ;
        vector<int> right;

        int i = s ;
        while(i <= mid){
            left.push_back(arr[i]);
            i++;
        }

        i = mid + 1 ;
        while(i <= e){
            right.push_back(arr[i]);
            i++;
        }

        // merging 
        int leftIndex = 0 ;
        int rightIndex = 0 ;
        int mainIndex = s ;
        while(leftIndex < left.size() && rightIndex < right.size()){
            if(left[leftIndex] < right[rightIndex]){
                arr[mainIndex] = left[leftIndex++];
            }
            else{
                arr[mainIndex] = right[rightIndex++];
            }
            mainIndex++;
        }

        while(leftIndex < left.size()){
            arr[mainIndex++] = left[leftIndex++];
        }

        while(rightIndex < right.size()){
            arr[mainIndex++] = right[rightIndex++];
        }
    }
        

    void mergeSort(vector<int>& arr , int s , int e){
        if(s >= e){
            return ;
        }
        int mid = s + (e - s) / 2 ;

        mergeSort(arr , s , mid);

        mergeSort(arr , mid+1 , e);

        merge(arr , s , e);

    }

    vector<int> sortArray(vector<int>& nums) {
        int e = nums.size() - 1 ;
        mergeSort(nums , 0 , e);
        return nums ;
    }
};