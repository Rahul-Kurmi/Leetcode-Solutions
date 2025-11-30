class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int row = arr.size();
        int col = arr[0].size();
        int start = 0 ;
        int end = row * col - 1;
        while(start <= end){
            int mid = start + (end - start)/2 ;
            int i = mid / col ;
            int j = mid % col ;
            if(arr[i][j] == target) return true ;
            else if(arr[i][j] > target) end = mid - 1 ;
            else start = mid + 1 ;
        } 
        return false ;
    }
};