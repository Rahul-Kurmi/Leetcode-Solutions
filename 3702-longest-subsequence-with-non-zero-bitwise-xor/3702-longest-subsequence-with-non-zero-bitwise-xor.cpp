class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resultXor = 0 ;
        bool allZero = true ; // to check if all elements are zero 

        for(int &x : nums){
            resultXor = resultXor ^ x ;

            if(x != 0){ // we found at least one element that is non-zero
                allZero = false ;
            }
        }

        if(allZero){
            return 0 ;
        }

        return resultXor == 0 ? n-1 : n ;

    }
};