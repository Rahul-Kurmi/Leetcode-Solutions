class Solution {
public:

    // THIS IS THE ONLY CODE THAT WILL HELP US IN PRINTING LIS --> PRINTING LIS CODE IN --> GFG
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // DP with LIS at each iindex 1 ie. element itself
        int maxLIS = 1 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){ // means jth element can form LIS with ith
                    // dp[i] --> max of dp[j] + 1 ie. LIS of jth and curr ith element and dp[i] 
                    dp[i] = max(dp[i] , dp[j] + 1);
                    maxLIS = max(dp[i] , maxLIS); 
                }
            }
        }

        // can do this as well if not updated maxLIS in loop
        // maxLIS = *max_element(dp.begin() , dp.end());
        return maxLIS ;
    }
};