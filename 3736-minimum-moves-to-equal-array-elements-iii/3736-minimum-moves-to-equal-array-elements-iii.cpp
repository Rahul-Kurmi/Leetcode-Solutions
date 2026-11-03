class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int maxEle = *max_element(nums.begin() , nums.end());

        int moves = 0 ;
        for(int num : nums){
            moves += (maxEle - num);
        }

        return moves ;
    }
};