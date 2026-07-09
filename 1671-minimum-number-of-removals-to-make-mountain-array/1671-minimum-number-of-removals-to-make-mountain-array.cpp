class Solution {
public:
    void getLisArray(vector<int>& arr, vector<int>& lis){
        vector<int> temp ;

        lis.push_back(1); // for 0th index, with element itself LIS = 1 
        temp.push_back(arr[0]);;

        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
                lis.push_back(temp.size()); // as now the element added in last of temp
            }
            else{
                int index = lower_bound(temp.begin() , temp.end() , arr[i]) - temp.begin();
                // now at this index will come the current element
                temp[index] = arr[i];

                // thus till this index we have lis with current element included
                lis.push_back(index + 1); 
            }
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis ;
        getLisArray(nums , lis);

        vector<int> lds ;
        reverse(nums.begin(), nums.end());
        getLisArray(nums, lds);


        int largestMountain = INT_MIN ;
        for(int i = 0 ; i < n ; i++){
            if(lis[i] == 1 || lds[n-i-1] == 1){  // if any is 1 --> no mountain array
                // lds[l-i-1] as we have reversed nums to get lds --> this gives corresponding lds
                continue ;
            }

            largestMountain = max(largestMountain , lis[i] + lds[n-i-1] - 1 );
        }


        int minRemoval = n - largestMountain ;
        return minRemoval;
    }
};