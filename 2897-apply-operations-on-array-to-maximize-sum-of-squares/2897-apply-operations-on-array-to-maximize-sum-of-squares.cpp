class Solution {
public:
    int MOD = 1e9+7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);

        // count all the bit positions of each number
        for(int &num  : nums){
            for(int bit = 0 ; bit <= 31 ; bit++){
                if(num & (1 << bit)){ // 1 << bit --> gives bit at exact position we want 
                    count[bit]++;
                }
            }
        }

        // now we have to make k largest digits
        int result = 0 ;

        while(k--){
            int value = 0 ;
            for(int bit = 0 ; bit <= 31 ; bit++){
                if(count[bit] > 0){ // we have bit present at here
                    count[bit]--;
                    value = value | (1 << bit) ; // Adding bit to the value 
                }
            }

            result = (result + (1LL * value * value) % MOD) % MOD ;
        }

        return result ;
    }
};