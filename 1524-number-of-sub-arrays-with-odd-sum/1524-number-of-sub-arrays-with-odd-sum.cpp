class Solution {
public:
    int MOD = 1e9 + 7 ;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int ans = 0 ;
        int evenCount = 0 , oddCount = 0 ;

        int preSum = 0 ;

        for(int i = 0 ; i < n ; i++){
            preSum += arr[i];

            if(preSum % 2 != 0){ // odd sum
                ans++;
                oddCount++;
                ans = (ans + evenCount) % MOD  ;
            }
            else{ // sum is even 
                evenCount++;
                ans = (ans + oddCount) % MOD  ;
            }
        }

        return ans ;
    }
};