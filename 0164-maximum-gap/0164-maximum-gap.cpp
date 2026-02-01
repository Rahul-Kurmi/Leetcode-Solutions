
class Solution {
public:
    int maximumGap(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        if(arr.size() <= 1) return 0 ;
        int i = 1 ;
        int maxGap = INT_MIN;
        while(i < arr.size()){
            int diff = arr[i] - arr[i-1];
            maxGap = max(diff, maxGap);
            i++;
        }
        return maxGap ;
    }
};