class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int k = 1 ;

        for(int i = 0 ; i < 31 ; i++){
            k = k << 1 | 1 ;
        }

        bool isSorted = true ;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i){
                k = k & nums[i];
                isSorted = false ;
            }
        }

        return !isSorted ? k : 0 ;
    }
};