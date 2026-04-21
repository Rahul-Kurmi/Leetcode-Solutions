class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] == 0) arr[i] = -1 ;
        }
        
        unordered_map<int, int> mp ;
        int maxLen = 0;
        int prefixSum = 0;
        mp[0] = 0 ;  // 1 based indexing in map
        for(int i = 0 ; i < arr.size() ; i++){
            prefixSum += arr[i];
            if(mp.find(prefixSum) != mp.end()){
                maxLen = max(maxLen , (i+1) - mp[prefixSum]);
            }
            else{
                mp[prefixSum] = i+1 ;
            }
        }
        return maxLen ;
    }
};