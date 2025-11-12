class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int i = arr.size() - 1 ;

        while(i >= 0){
            if(arr[i] + 1 != 10){
                arr[i] += 1 ;
                return arr;
            }
            arr[i] = 0 ;
            if
            (i == 0){
                arr.insert(arr.begin() , 1);
            }
            i--;
        }
        return arr ;
    }
};