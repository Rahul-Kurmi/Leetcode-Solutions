class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() == 1 ) return 0 ;
        sort(nums.begin(), nums.end());
        int i = 0 ;
        int j = i + 1 ;
        set<pair<int, int>> ans ;
        while(j < nums.size()){
            if(i == j){
                j++;
                continue;
            }
            int diff = nums[j] - nums[i];
            if(diff == k){
                pair<int ,int> pp ;
                pp = make_pair(nums[i] , nums[j]);
                ans.insert(pp);
                i++;
                j++;
            }
            else if(diff > k){
                i++;
            }
            else{
                j++;
            }
        }
        return ans.size();
    }
};