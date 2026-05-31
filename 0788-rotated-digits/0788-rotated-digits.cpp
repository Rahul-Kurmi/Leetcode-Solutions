class Solution {
public:
    
    bool isGood(int num){
        bool changed = false;
        while(num > 0){
            int digit = num % 10 ;

            //invalid digits --> 3, 4, 7
            if(digit == 3 || digit == 4 || digit == 7) return false ;

            // Valid digits -> 0, 1, 8, 2, 5, 6, 9 
            // but only 2, 5, 6, 9, can raotate 180 to create new digit --> new num
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                changed = true ;
            }

            num /= 10 ;
        }

        return changed ;
    }

    int rotatedDigits(int n) {
        int count = 0 ;

        for(int i = 1 ; i <= n ; i++){
            if(isGood(i)){
                count++;
            }
        }

        return count;
    }
};