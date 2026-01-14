class Solution {
public:
    bool isValidDigit(int n , int i , int val){
        if(val == n) return true;
        if(val > n) return false ;
        if(val > INT_MAX/i) return false;
        return isValidDigit(n , i , val*i);
    }

    bool isPowerOfTwo(int n) {
        return isValidDigit(n , 2, 1);
    }
};