//Approach-1 (Greedily Pick mid element)
//T.C : O(nlogn) for sorting
//S.C : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int mid = nums[n/2];

        int moves = 0;
        for(int i = 0; i < n; i++) {
            moves += abs(nums[i] - mid);
        }

        return moves;
    }
};