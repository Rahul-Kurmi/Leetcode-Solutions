class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> arr;
        for (auto it : nums) {
            if (it == val) continue; 
            arr.push_back(it);
        }

        nums.clear();  // clear original nums

        for (auto it : arr) {
            nums.push_back(it);
        }

        return nums.size();
    }
};
