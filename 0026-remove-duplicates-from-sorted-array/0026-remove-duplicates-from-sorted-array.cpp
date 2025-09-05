class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // slow pointer
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) { // found new unique value
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1; // length of unique elements
    }
};
