class Solution {
public:
    long long sumAndMultiply(int n) {
        long long digit = 0 ;
        long long sum = 0 ;
        int i = 0 ;
        while(n != 0){
            int rem = n % 10 ;
            sum += rem ;
            if(rem != 0){
                digit = rem * pow(10 , i) + digit ;
                i++;
            }
            n = n / 10 ;
        }
        return digit * sum ;
    }
};