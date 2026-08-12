class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp ;
        int i = 0 ; 
        int j = 0 ;
        int maxLen = 0 ;
        while(j < nums.size()){
            int element = nums[j];
            if(mp[element] < k){
                mp[element]++;
                maxLen = max(maxLen , j - i + 1);
                j++;
            }
            else{
                while(nums[i] != element){
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                i++;
            }
        }
        return maxLen; 
    }
};