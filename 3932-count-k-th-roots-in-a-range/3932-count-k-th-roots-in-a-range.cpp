class Solution {
public:

    bool possible(long long mid, int k, long long n) {

        long long ans = 1;

        for(int i = 0; i < k; i++) {

            if(mid != 0 && ans > n / mid)
                return false;

            ans *= mid;
        }

        return true;
    }

    long long kthRoot(long long n, int k) {

        long long low = 0;
        long long high = n;
        long long ans = 0;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            if(possible(mid, k, n)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int countKthRoots(int l, int r, int k) {

        long long right = kthRoot(r, k);

        long long left = (l == 0)
                         ? 0
                         : kthRoot((long long)l - 1, k);

        long long ans = right - left;

        if(l == 0)
            ans++;

        return (int)ans;
    }
};