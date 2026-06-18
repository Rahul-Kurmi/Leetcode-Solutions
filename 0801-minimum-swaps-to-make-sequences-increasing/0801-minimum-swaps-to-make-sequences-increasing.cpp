class Solution {
public:
    int minSwapHeler(vector<int>& nums1, vector<int>& nums2, int i, vector<vector<int>>& dp, int isSwap){
        if(i == nums1.size()) return 0 ;

        if(dp[i][isSwap] != -1) return dp[i][isSwap];

        int swap = INT_MAX , noSwap = INT_MAX ;

        int prev1 , prev2 ; 
        if(i == 0){ // this is neceasry as when i = 0, we can't acces (i-1)th index
            prev1 = -1;
            prev2 = -1;
        }
        else if(isSwap){
            prev1 = nums2[i-1];
            prev2 = nums1[i-1];
        }
        else{
            prev1 = nums1[i-1];
            prev2 = nums2[i-1];
        }

        if(prev1 < nums2[i] && prev2 < nums1[i]){
            // now after swap --> new prev1 = nums2[i] , new prev2 = nums1[i]
            swap = 1 + minSwapHeler(nums1, nums2, i+1, dp, 1);
        }

        if(prev1 < nums1[i] && prev2 < nums2[i]){
            // swap not done as prev is already smaller --> this prev1 = nums1[i], prev2 = nums2[i]
            noSwap = 0 + minSwapHeler(nums1, nums2, i+1, dp , 0);
        }

        return dp[i][isSwap] = min(swap , noSwap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1 , vector<int>(2, 0));
        // TABULATION CODE 

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int isSwap = 1; isSwap >= 0 ; isSwap--){
                int swap = INT_MAX , noSwap = INT_MAX ;
                int prev1 , prev2 ; 
                if(i == 0){ // this is neceasry as when i = 0, we can't acces (i-1)th index
                    prev1 = -1;
                    prev2 = -1;
                }
                else if(isSwap){
                    prev1 = nums2[i-1];
                    prev2 = nums1[i-1];
                }
                else{
                    prev1 = nums1[i-1];
                    prev2 = nums2[i-1];
                }


                if(prev1 < nums2[i] && prev2 < nums1[i]){
                    swap = 1 + dp[i+1][1];
                }

                if(prev1 < nums1[i] && prev2 < nums2[i]){
                    noSwap = 0 + dp[i+1][0];
                }

                dp[i][isSwap] = min(swap , noSwap);
            }
        }

        return dp[0][0];
    }
};