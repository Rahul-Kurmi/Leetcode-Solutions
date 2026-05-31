class Solution {
public:

    int solve(int num){
        // BASE CASE if num == 0 valid but, can't change thus return 0  
        if(num == 0) return 0 ;

        int remainingCheck = solve(num / 10);

        int currDigit = num % 10 ;
        int currCheck;

        if(currDigit == 0 || currDigit == 1 || currDigit == 8) {
            currCheck = 0 ; // valid digit but doest't change the number 
        }
        else if(currDigit == 2 || currDigit == 5 || currDigit == 6 || currDigit == 9){
            currCheck = 1 ; // valid digit and change the number
        } 
        else{ // means currDigit is 3  or  4 or 7 
            currCheck = 2 ;
        }

        if(remainingCheck == 0 && currCheck == 0) return 0 ;
        else if(remainingCheck == 2 || currCheck == 2) return 2 ;
        else return 1 ;
    }

    int rotatedDigits(int n) {
        int count = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if(solve(i) == 1) count++;
        }

        return count ;
    }
};