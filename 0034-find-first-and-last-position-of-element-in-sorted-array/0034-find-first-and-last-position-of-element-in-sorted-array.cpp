class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        int firstPos = -1, lastPos = -1;

        // must check that left != end before dereferencing
        if (left != nums.end() && *left == target) {
            firstPos = left - nums.begin();
        }

        // safe check for last position
        if (right != nums.begin() && *(right - 1) == target) {
            lastPos = (right - nums.begin()) - 1;
        }

        return {firstPos, lastPos};
    }
};
