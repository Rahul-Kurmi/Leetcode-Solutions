class Solution {
public:
    int reverseBits(int n) {
        if(n == 0) return 0 ;
        int reverseAns = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            reverseAns = reverseAns << 1 ;
            if(n & 1){
                reverseAns = reverseAns | 1 ; 
            }else{
                reverseAns = reverseAns | 0 ; 
            }
            n = n >> 1 ;
        }
        return reverseAns;
    }
};