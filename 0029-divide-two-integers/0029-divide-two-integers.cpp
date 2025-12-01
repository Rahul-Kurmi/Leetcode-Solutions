class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX ;
        
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long absDividend = abs((long long) dividend);
        long long absDivisor = abs((long long) divisor);
        

        long long start = 0 ;
        long long end = absDividend ;
        long long ans = 0;
        while(start <= end){
            long long mid = start + (end - start) / 2 ;
            if(mid * absDivisor == absDividend){
                ans = mid ;
                break ;
            }
            else if(mid * absDivisor > absDividend){
                end = mid -1 ;
            }
            else{
                ans = mid ;
                start = mid + 1 ;
            }
        }
        return (negative) ? -ans : ans ;
    }
};