class Solution {
public:
    int count = 0 ;
    void beautifulArrangements(vector<int>& arr , int start, int numPlace, int numCount){
        if(numCount == 0){
            count++;
            return ;
        }

        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] == 0){
                if((numPlace % (i+1) == 0) || ((i+1) % numPlace) == 0){
                    arr[i] = numPlace ;
                    beautifulArrangements(arr, start , numPlace+1 , numCount-1);
                    arr[i] = 0 ;
                }
            }
        }
    }

    int countArrangement(int n) {
        vector<int> arr(n , 0);
        beautifulArrangements(arr, 0 , 1, n);
        return count ;
    }
};