class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessThanTarget = 0 ;
        int equalToTarget = 0 ;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < target){
                lessThanTarget++;
            }
            else if(nums[i] == target){
                equalToTarget++;
            }
        }
        
        vector<int> ans ;

        for(int i = 0 ; i < equalToTarget; i++){
            ans.push_back(lessThanTarget++);
        }

        return ans ;
    }
};