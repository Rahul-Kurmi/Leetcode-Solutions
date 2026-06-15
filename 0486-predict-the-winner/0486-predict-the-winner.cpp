class Solution {
public:
    int solve(vector<int>& nums, int start , int end){
        if(start == end) return nums[start];

        // diff = P1 - P2
        int diffByStart = nums[start] - solve(nums, start+1 , end);
        int diffByEnd = nums[end] - solve(nums, start, end-1);

        return max(diffByStart , diffByEnd);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0 , n-1) >= 0;
    }
};