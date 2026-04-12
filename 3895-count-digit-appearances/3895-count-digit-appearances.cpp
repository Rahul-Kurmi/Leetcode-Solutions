class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0 ;
        for(auto it : nums){
            while(it != 0 ){
                int rem = it % 10 ;
                if(rem == digit) count++;
                it = it / 10 ;
            }
        }
        return count ;
    }
};