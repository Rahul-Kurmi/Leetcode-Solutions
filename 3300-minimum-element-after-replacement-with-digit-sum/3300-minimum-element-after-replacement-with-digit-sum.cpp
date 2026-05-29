class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX ;
        for(auto num: nums){
            int sum = 0 ;
            while(num > 0 ){
                sum += num % 10 ;
                num /= 10;
            }

            ans = min(sum , ans);
        }

        return ans ;
    }
};