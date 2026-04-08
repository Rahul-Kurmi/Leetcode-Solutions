class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest = -1 ;
        for(int i = arr.size() -1 ; i >= 0 ; i--){
            int value = greatest ;
            greatest = max(arr[i] , greatest);
            arr[i] = value ;
        }

        return arr ;
    }
};