class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>freq1(101 , 0);
        vector<int>freq2(101 , 0);
        for(int i = 0 ; i < nums1.size() ; i++){
            freq1[nums1[i]]++;
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            freq2[nums2[i]]++;
        }
        int count1 = 0 ;
        for(int i = 0 ; i < nums2.size() ; i++){
            if(freq1[nums2[i]] > 0){
                count1++;
            }
        }
        int count2 = 0 ;
        for(int i = 0 ; i < nums1.size() ; i++){
            if(freq2[nums1[i]] > 0){
                count2++;
            }
        }

        return {count2 , count1};
    }
};