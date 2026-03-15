class Solution {
public:
    int countCommas(int n) {
        int ans = n - 998 - 1 ;
        return ans < 0 ? 0 : ans ;
    }
};