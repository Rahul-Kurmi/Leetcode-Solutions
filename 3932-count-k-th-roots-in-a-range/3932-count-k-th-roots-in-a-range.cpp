class Solution {
public:
    using ll = long long; 
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1 ;

        int count = 0 ;
        for(ll i = 1 ; i <= sqrt(1e9) ; i++){
            ll val = 1 ;
            int x = k ;
            while(x--){
                if(val > r) break ;
                val *= i ;
            }
            if(val >= l && val <= r) count++; 
        }

        if(l == 0) count++ ;

        return count ;
    }
};