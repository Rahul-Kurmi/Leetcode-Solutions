class Solution {
public:
    int solveForP1(vector<int>& nums , int i, int j){
        if(i > j) return 0 ;
        if(i == j) return nums[i];

        int take_i = nums[i] + min(solveForP1(nums, i+2 , j), solveForP1(nums, i+1, j-1));
        int take_j = nums[j] + min(solveForP1(nums, i+1, j-1), solveForP1(nums, i, j-2));

        return max(take_i , take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        
        int player1Sum = solveForP1(nums, 0 , n-1);
        int player2Sum = totalSum - player1Sum ;

        return player1Sum >= player2Sum ;
    }
};