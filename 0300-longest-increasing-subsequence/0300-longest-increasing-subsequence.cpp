class Solution {
public:
    int lowerBoundIndex(vector<int>& temp , int target){
        int start = 0;
        int end = temp.size() - 1;
        while(start < end){
            int mid = start + (end - start) / 2 ;
            if(temp[mid] < target){
                start = mid + 1; 
            }
            else{
                end = mid; 
            }
        } 

        return end ;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        // int len = 0 ;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                // len++;
            }
            else{
                // we can also use 
                // int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();

                int index = lowerBoundIndex(temp , nums[i]);
                temp[index] = nums[i];
            }
        }

        return (int)temp.size(); // or just return len
    }
};