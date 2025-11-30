class Solution {
public:

    int maximumIndex(vector<int> &arr){
        int start = 0 ;
        int end = arr.size() - 1;
        while(start < end){
            int mid = start + (end - start)/2 ;
            if(arr[mid] > arr[mid + 1]){
                return mid;
            }
            if(arr[mid] > arr[end]){
                start = mid + 1;  // Maximum is in the right half
            }else{
                end = mid;  // Maximum is in the left half
            }
        }
        return start ;
    }

    int binarySearch(vector<int> &arr, int target , int start , int end) {

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;      // target found
            }
            else if (arr[mid] < target) {
                start = mid + 1; // go right
            }
            else {
                end = mid - 1;   // go left
            }
        }

        return -1; // not found
    }


    int search(vector<int>& arr, int target) {
        int maxIndex = maximumIndex(arr);
        cout << maxIndex ;
        int leftSearch = binarySearch(arr, target , 0 , maxIndex);
        int rightSearch = binarySearch(arr, target , maxIndex + 1, arr.size() - 1);

        int ans = (leftSearch !=  -1) ? leftSearch : rightSearch ;
        return ans ;
    }
};