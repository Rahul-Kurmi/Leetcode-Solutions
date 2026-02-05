class Solution {
public:
    void findCrossSum(vector<int>& arr, int start, int end, int& maxSum){
        int mid = start + (end - start) / 2 ;

        int maxLeftBorderSum = INT_MIN ;
        int maxRightBorderSum = INT_MIN ;

        int leftBorderSum = 0 ;
        int rightBorderSum = 0 ;

        for(int i = mid ; i >= start ; i--){
            leftBorderSum += arr[i];
            maxLeftBorderSum = max(maxLeftBorderSum , leftBorderSum);
        }

        for(int i = mid+1; i <= end ; i++){
            rightBorderSum += arr[i];
            maxRightBorderSum = max(maxRightBorderSum , rightBorderSum);
        }

        int crossSum = maxLeftBorderSum + maxRightBorderSum ;

        maxSum = max(maxSum , crossSum);

    }

    void maxSubArrayRec(vector<int>& arr, int start, int end, int& maxSum){
        if(start == end){
            maxSum = max(maxSum , arr[start]);
            return ;
        }

        int mid = start + (end - start) / 2 ;

        maxSubArrayRec(arr, start , mid , maxSum);
        maxSubArrayRec(arr, mid+1 , end , maxSum);

        findCrossSum(arr, start , end , maxSum);
    }

    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        maxSubArrayRec(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};