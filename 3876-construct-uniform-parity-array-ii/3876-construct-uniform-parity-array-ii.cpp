class Solution {
public:
    bool uniformArray(vector<int>& arr) {
        // Without SORT in log(n)

        bool oddFound = false ;
        int miniOdd = INT_MAX ;
        for(auto it : arr){
            if(it % 2 == 1){
                oddFound = true ;
                miniOdd = min(miniOdd, it);
            }
        }

        // IF no odd found --> All even 
        if(!oddFound) return true ;

        // Check if there's any even number greater than this smallest odd
        // if there is then can't make all odd 
        // as --> 2 - 3 = -1 (if 3 smallest odd) (if 2 smallest even)
        for(auto it : arr){
            if(it % 2 == 0 && it < miniOdd) return false ;
        }

        return true ;
    }
};