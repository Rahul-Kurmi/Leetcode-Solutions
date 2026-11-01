//Approach-2 
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int min_el = *min_element(begin(nums), end(nums));
        
        int operations = 0 ;

        // trying to convet all the element as minimum element
        for(int i = 0 ; i < n ; i++){
            operations += nums[i] - min_el;
        }

        return operations ;
    }
};
