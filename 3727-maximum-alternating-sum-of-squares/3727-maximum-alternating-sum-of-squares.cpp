
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // Counting sort: store the frequency of absolute values
        vector<int> count((4 * 1e4) + 1, 0);

        for(int i = 0; i < n; i++){
            int num = abs(nums[i]);
            count[num]++;
        }

        long long minusValue = 0;
        int minusElements = n / 2;

        long long plusValue = 0;
        int plusElements = n - minusElements;

        // Assign the smallest elements to negative positions
        for(int i = 0; i <= 4 * 1e4; i++){
            int currCount = count[i];

            while(currCount){
                minusValue += 1LL * i * i;
                minusElements--;
                currCount--;

                if(minusElements == 0) break;
            }

            count[i] = currCount;

            if(minusElements == 0) break;
        }

        // Assign the remaining largest elements to positive positions
        for(int i = 4 * 1e4; i >= 0; i--){
            int currCount = count[i];

            while(currCount){
                plusValue += 1LL * i * i;
                plusElements--;
                currCount--;

                if(plusElements == 0) break;
            }

            count[i] = currCount;

            if(plusElements == 0) break;
        }

        return plusValue - minusValue;
    }
};