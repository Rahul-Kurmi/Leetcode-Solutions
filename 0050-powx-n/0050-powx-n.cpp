class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1 ;
        long long N = n ;
        if(N < 0 ){
            x = 1 / x ;
            N = -N ;
        }
        double result = 1 ;
        while(N > 0){
            if(N % 2){
                result = result * x ;
            }

            x = x * x ;
            N = N / 2;
        }
        return result ;
    }
};