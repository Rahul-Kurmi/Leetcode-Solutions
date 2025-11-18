class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> result(nums.size());
        int posIdx = 0;  // For even indices (0, 2, 4...)
        int negIdx = 1;  // For odd indices (1, 3, 5...)
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                result[posIdx] = nums[i];
                posIdx += 2;
            } else {
                result[negIdx] = nums[i];
                negIdx += 2;
            }
        }
        
        return result;
    }
};