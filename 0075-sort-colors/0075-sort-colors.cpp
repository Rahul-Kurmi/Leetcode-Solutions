class Solution {
public:
    void sortColors(vector<int>& arr) {
        int start = 0;
        int mid = 0;
        int end = arr.size() -1 ;
        while(mid <= end){
            if(arr[start] == 0) {
                start++;
                mid++;
            }
            else if(arr[end] == 2) end--;
            else if(arr[mid] == 0){
                swap(arr[start] , arr[mid]);
                start++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else if(arr[mid] == 2){
                swap(arr[mid] , arr[end]);
                end--;
            }
        }
    }
};