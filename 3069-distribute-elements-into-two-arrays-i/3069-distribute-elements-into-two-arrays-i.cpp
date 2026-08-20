class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 ;
        vector<int> arr2 ;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int i = 2 ;
        while(i < nums.size()){
            int arr1_last = arr1.back();
            int arr2_last = arr2.back();

            if(arr1_last > arr2_last){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }

            i++;
        }

        vector<int> result(arr1.begin() , arr1.end());
        result.insert(result.end() , arr2.begin(), arr2.end());

        return result ;
    }
};