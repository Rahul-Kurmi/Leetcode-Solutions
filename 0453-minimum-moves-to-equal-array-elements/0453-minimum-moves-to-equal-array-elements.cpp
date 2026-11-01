//Approach-3 (Two Pass)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
  
        int sum    = accumulate(begin(nums), end(nums), 0);
        int min_el = *min_element(begin(nums), end(nums));

        return sum - n*min_el;
    }
};