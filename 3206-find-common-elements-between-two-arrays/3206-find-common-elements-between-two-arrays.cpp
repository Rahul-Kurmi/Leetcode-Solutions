class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1 (nums1.begin() , nums1.end());
        set<int> s2 (nums2.begin() , nums2.end());
        int count1 = 0 ;
        for(int num : nums2){
            if(s1.count(num)){
                count1++;
            }
        }
        int count2 = 0 ;
        for(int num : nums1){
            if(s2.count(num)){
                count2++;
            }
        }

        return {count2 , count1};
    }
};