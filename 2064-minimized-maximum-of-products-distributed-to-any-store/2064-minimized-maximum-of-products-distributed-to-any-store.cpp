class Solution {
public:
    bool isPossible(vector<int>& arr , int mid , int n){
        int count = 0 ;
        for(int i = 0 ; i < arr.size() ; i++){
            count += arr[i]/mid ;
            if(arr[i] % mid) count++;
        }
        return count <= n;
    }



    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1 ;
        int end = *max_element(quantities.begin() , quantities.end());
        int ans = 0 ;
        while(start <= end){
            int mid = start + (end - start)/2 ;
            if(isPossible(quantities , mid  , n)){
                ans = mid ;
                end = mid - 1 ;
            }
            else{
                start = mid + 1 ;
            }
        }
        return ans ;
    }
};