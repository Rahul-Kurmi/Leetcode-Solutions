class Solution {
public:
    int minSwapHeler(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2){
        if(i == nums1.size()) return 0 ;

        int swap = INT_MAX , noSwap = INT_MAX ;
        if(prev1 < nums2[i] && prev2 < nums1[i]){
            // now after swap --> new prev1 = nums2[i] , new prev2 = nums1[i]
            swap = 1 + minSwapHeler(nums1, nums2, i+1, nums2[i], nums1[i]);
        }

        if(prev1 < nums1[i] && prev2 < nums2[i]){
            // swap not done as prev is already smaller --> this prev1 = nums1[i], prev2 = nums2[i]
            noSwap = 0 + minSwapHeler(nums1, nums2, i+1, nums1[i] , nums2[i]);
        }

        return min(swap , noSwap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        return minSwapHeler(nums1, nums2, 0, -1 , -1);
    }
};