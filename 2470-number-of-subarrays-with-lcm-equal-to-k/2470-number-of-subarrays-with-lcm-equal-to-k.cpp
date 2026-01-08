class Solution {
public:
    int findHCF(int a, int b){
        if(b == 0) return a;
        return findHCF(b, a % b);
    }

    int lcm(int a, int b){
        return (a / findHCF(a, b)) * b;   // safe from overflow
    }

    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int currLCM = 1;

            for(int j = i; j < n; j++){
                currLCM = lcm(currLCM, nums[j]);

                if(currLCM == k) {
                    count++;
                }

                // optimization: LCM only increases
                if(currLCM > k) break;
            }
        }
        return count;
    }
};
