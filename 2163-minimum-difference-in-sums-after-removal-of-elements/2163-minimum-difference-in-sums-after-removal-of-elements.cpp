class Solution {
public:
    using ll = long long;
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3 ;
        vector<ll>nPrefixSum(nums.size() , -1) , nSuffixSum(nums.size() , -1);
        // nPrefixSum[i] --> sum of first n mininum elements from left 
        // nSuffixSum[i] --> sum of first n maximum elements from right

        ll sum = 0 ;
        priority_queue<ll> maxHeap ;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            maxHeap.push(nums[i]);

            // pop out max element 
            if(maxHeap.size() > n){
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if(maxHeap.size() == n){
                nPrefixSum[i] = sum ;
            }
        }

        sum = 0 ;
        priority_queue<ll , vector<ll> ,  greater<ll>> minHeap;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            sum += nums[i];
            minHeap.push(nums[i]);

            // pop out min element
            if(minHeap.size() > n){
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == n){
                nSuffixSum[i] = sum;
            }
        }

        ll ans = LONG_LONG_MAX;

        for(int i = n-1 ; i < 2*n ; i++){
            ans = min(ans , nPrefixSum[i] - nSuffixSum[i+1]);
        }
        return ans ;
    }
};