class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size() ;
        int sum = 0 ;
        int ansCount = 0 ;
        
        // for 1st subarray 
        for(int i = 0 ; i < k ; i++){
            sum += arr[i];
        }

        if(sum / k >= threshold) ansCount++;

        // slide window
        for(int i = k ; i < arr.size() ; i++){
            // add current Element 
            sum += arr[i];
            // remove 1st in window 
            sum -= arr[i - k];

            if(sum / k >= threshold) ansCount++;
        }

        return ansCount ;
    }
};