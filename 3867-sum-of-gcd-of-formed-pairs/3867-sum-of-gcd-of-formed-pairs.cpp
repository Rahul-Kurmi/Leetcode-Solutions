class Solution {
public:
    
    long long gcdFind(long long a, long long b){
        while(a){
            long long t = a;
            a = b % a;
            b = t;
        }
        return b;
    }
    
    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> prefixGcd;
        
        long long mxi = nums[0];
        
        for(int i = 0; i < n; i++){
            mxi = max(mxi , (long long)nums[i]);
            prefixGcd.push_back(gcdFind(mxi , nums[i]));
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long ans = 0;
        
        int left = 0;
        int right = n - 1;
        
        while(left < right){
            ans += gcdFind(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return ans;
    }
};