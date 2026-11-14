// Improved Brute Force 
//T.C : O(n*(r-l+1))
//S.C : O(n)

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int result = INT_MAX ;

        for(int i = 0 ; i < n ; i++){
            for(int j = i + l - 1 ; j < n && j <= i + r - 1 ; j++){
                int sum = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);
                if (sum > 0) 
                    result = min(result, sum);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};