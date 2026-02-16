class Solution {
public:
    int reverseBits(int n) {
        if(n == 0) return 0 ;
        int reverseAns = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            reverseAns <<= 1 ;

            reverseAns = reverseAns | (n & 1) ;

            n >>= 1;
        }
        return reverseAns;
    }
};