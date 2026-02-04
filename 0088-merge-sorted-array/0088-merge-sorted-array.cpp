class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total_elements = m + n ;
        int gap = (total_elements / 2 ) + (total_elements % 2) ;
        while(gap > 0){
            int i = 0 ;
            int j = i + gap ;
            while(j < total_elements){
                if(i < m && j < m){
                    if(nums1[i] > nums1[j]){
                        swap(nums1[i] , nums1[j]);
                    }
                }
                else if(i < m && j >= m){
                    if(nums1[i] > nums2[j-m]){
                        swap(nums1[i] , nums2[j-m]);
                    }
                }
                else if(i >= m && j >= m){
                    if(nums2[i - m] > nums2[j - m]){
                        swap(nums2[i - m] , nums2[j - m]);
                    }
                }
                i++;
                j++;
            }
            gap = (gap == 1) ? 0 : (gap / 2 ) + (gap % 2) ;
        } 


        int k = m ;
        for(int i = 0 ; i < n ; i++){
            nums1[k++] = nums2[i];
        }
    }
};