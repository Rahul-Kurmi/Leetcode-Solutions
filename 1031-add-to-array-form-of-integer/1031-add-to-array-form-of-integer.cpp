class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int i = nums.size() - 1;
        int carry = 0;

        // Process the array from right to left
        while (i >= 0 || k > 0) {
            int digitFromK = k % 10; 
            k = k / 10;

            int element = carry + digitFromK;

            if (i >= 0) {
                element += nums[i];
                nums[i] = element % 10;
                i--;
            } else {
                nums.insert(nums.begin(), element % 10);
            }

            carry = element / 10;
        }

        // If carry remains, insert it
        if (carry != 0) {
            nums.insert(nums.begin(), carry);
        }

        return nums;
    }
};
