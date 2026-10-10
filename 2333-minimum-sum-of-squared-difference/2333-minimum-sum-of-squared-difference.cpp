//Approach (Using Counting Sort)
//T.C : O(n + maxDiff), maxDiff <= 10^5
//S.C : O(n)
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        // countDiff[d] = conut of each diff
        vector<int> countDiff(maxDiff + 1, 0);
        for (int d : diff) {
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
        
            int countOps             = min(countDiff[currDiff], K);

            countDiff[currDiff]     -= countOps; // as this diff is changed 
            countDiff[currDiff - 1] += countOps; // this is new diff we got 
            K                       -= countOps; // no. of ops used
        }

        
        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            // as we have diff as index and count as value 
            // thus diff's square ==> d*d 
            // no of times it came ==> countDiff[d]
            result += countDiff[d] * d * d; // this is n times diff^2 
        }

        return result;
    }
};