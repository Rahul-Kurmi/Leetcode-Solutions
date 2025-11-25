class Solution {
public:
    int clumsy(int n) {
        if(n < 3) return n;
        if(n == 3) return 6;
        int res = (n) * (n - 1) / (n - 2) + (n - 3);
        n -= 4;
        while(n > 0){
            int curr = n--;
            if(n) curr *= n--;
            if(n) curr /= n--;
            res += (n--) - curr;
        }
        return res;
    }
};