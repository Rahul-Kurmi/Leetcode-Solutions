class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans ;
        int diff = INT_MAX;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            int j = i + 1 ;
            int k = nums.size() - 1 ;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < diff){
                    diff = abs(target - sum); 
                    ans = sum ;
                }
                if (sum == target) {
                    return target;
                }
                else if (sum < target) {
                    j++;  
                }
                else {
                    k--;  
                }
            }
        }
        return ans ;
    }
};