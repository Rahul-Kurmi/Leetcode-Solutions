class Solution {
public:

    bool bs(vector<int> &nums, int start, int x) {
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == x) {
                return true;
            } else if (nums[mid] > x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            int target = nums[i] + k ;
            if(i - 1 >= 0 && nums[i] == nums[i-1]) continue ;
            if(bs(nums , i + 1 , target)) ans++;
        }
        return ans ;
    }
};