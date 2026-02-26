class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> arr ;
        k = k % nums.size();
        if (k == 0) return; 

        for(int i = nums.size() - k ; i  < nums.size() ; i++){
            arr.push_back(nums[i]);
        }
        for(int i = 0 ; i < nums.size() - k ; i++){
            arr.push_back(nums[i]);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = arr[i];
        }

    }
};