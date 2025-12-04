class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums[0] >= 0){
            int i = 0 ;
            while (i < nums.size() && nums[i] == 0){
                i++;
            }
            if(i == nums.size()) return 0 ;
            return nums.size() - i;
        }
        if(nums[nums.size() - 1 ] < 0 ) return nums.size();


        auto LB = lower_bound(nums.begin() , nums.end() , 0);
        int firstPos = LB - nums.begin();
        int i = firstPos ;
        while(nums[i] == 0){
            i++;
        }

        int totalNegative = firstPos ;
        cout << totalNegative << endl ;
        int totalPositive = nums.size() - i;
        cout << totalPositive;

        return max(totalNegative , totalPositive);
    }
};