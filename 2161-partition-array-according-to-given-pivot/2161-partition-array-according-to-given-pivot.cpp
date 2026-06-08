//Approach-3 (Using pointers only)
//T.C : O(n)
//S.C : O(n) or O(1) if ans not included
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0 ;
        int right = n - 1;
        int i = 0 ;
        int j = n-1 ;
        while(i < n){
            if(nums[i] < pivot){
                ans[left++] = nums[i];
            }

            if(nums[j] > pivot){
                ans[right--] = nums[j];
            }

            i++;
            j--;
        }

        while(left <= right){
            ans[left++] = pivot;
        }

        return ans ;
    }
}; 