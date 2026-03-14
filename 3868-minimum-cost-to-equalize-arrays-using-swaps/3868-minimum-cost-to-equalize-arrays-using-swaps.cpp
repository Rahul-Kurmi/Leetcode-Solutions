class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freqCount ;
        for(auto it : nums1) freqCount[it]++;
        for(auto it : nums2) freqCount[it]++;

        for(auto &it : freqCount){
            if(it.second % 2) return -1 ;
        }

        unordered_map<int,int> diff ;
        for(auto it : nums1) diff[it]++;
        for(auto it : nums2) diff[it]--;

        int misMatch = 0 ;
        for(auto &it : diff){
            misMatch += abs(it.second);
        }

        return misMatch/4 ;
    }
};