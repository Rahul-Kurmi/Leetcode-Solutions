class Solution {
public:

    int lowerbound(vector<int>& arr, int x) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = end;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (arr[mid] >= x) {
                ans = mid; 
                end = mid - 1; 
            } else {
                start = mid + 1; 
            }
        }
        return ans; 
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int high = lowerbound(arr , x);
        int low = high - 1;
        while(k--){
            if(low < 0){
                high++;
            }
            else if(high >= arr.size()){
                low--;
            }
            else if(arr[high] - x >= x - arr[low]){
                low--;
            }
            else{
                high++;
            }
        }  

        return vector<int>(arr.begin() + (low + 1) , arr.begin() + high ) ;
    }
};