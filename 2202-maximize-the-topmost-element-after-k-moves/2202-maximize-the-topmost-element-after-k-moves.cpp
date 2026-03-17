class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 0) return nums[0];
        if (n == 1) return (k % 2 == 0) ? nums[0] : -1;
        if (k == 1) return nums[1];


        int x = k - 1 ;
        int maxi = 0 ;
        int i = 0 ;
        while(x--  && i < nums.size()){
            maxi = max(maxi, nums[i]);
            i++;
        }

        int nextMax = 0 ;
        if(i + 1 < nums.size()){
            nextMax = nums[i+1];
        }

        if(nextMax > maxi) return nextMax ;
        return maxi ;
    }
};