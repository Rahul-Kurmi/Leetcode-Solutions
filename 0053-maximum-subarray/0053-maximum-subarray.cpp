class Solution {
public:
    int maxSumArrayHelper(vector<int>& arr, int start , int end){
        if(start == end) {
            return arr[start];
        }

        int mid = start + (end - start) / 2; 
 
        int leftSum = maxSumArrayHelper(arr, start , mid) ;
        int rightSum = maxSumArrayHelper(arr, mid+1 , end) ;

        int maxLeftBorderSum = INT_MIN ;
        int maxRightBorderSum = INT_MIN ;

        int leftBorderSum = 0 ;
        int rightBorderSum = 0 ;

        for(int i = mid ; i >= start ; i--){
            leftBorderSum += arr[i];
            maxLeftBorderSum = max(maxLeftBorderSum , leftBorderSum);
        }

        for(int i = mid + 1 ; i <= end ; i++){
            rightBorderSum += arr[i];
            maxRightBorderSum = max(maxRightBorderSum , rightBorderSum);
        }

        int crossSum = maxLeftBorderSum + maxRightBorderSum  ;

        return max({leftSum , rightSum , crossSum});
    }

    int maxSubArray(vector<int>& nums) {
        return maxSumArrayHelper(nums, 0 , nums.size() - 1);
    }
};