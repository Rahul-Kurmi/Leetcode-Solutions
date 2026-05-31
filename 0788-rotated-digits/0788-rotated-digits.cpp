class Solution {
public:

    int solve(int num , vector<int>& dp){
        // BASE CASE if num == 0 valid but, can't change thus return 0  
        if(num == 0) return 0 ;

        if(dp[num] != -1) return dp[num];

        int remainingCheck = solve(num / 10 , dp);

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

        if(remainingCheck == 0 && currCheck == 0) return dp[num] =  0 ;
        else if(remainingCheck == 2 || currCheck == 2) return dp[num] =  2 ;
        else return dp[num] =  1 ;
    }

    int rotatedDigits(int n) {
        int count = 0 ;

        // 0 : same 
        // 1 : good
        // 2 : invalid

        // CONVERTING INTO TABULATION
        

        vector<int> dp(n+1, -1);
        dp[0] = 0 ;

        for(int i = 1 ; i <= n ; i++){

            int remainingCheck = dp[i / 10] ;

            int currDigit = i % 10 ;
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

            if(remainingCheck == 0 && currCheck == 0) dp[i] =  0 ;
            else if(remainingCheck == 2 || currCheck == 2) dp[i] =  2 ;
            else{
                dp[i] = 1 ;
                count++;
            }
        }

        return count ;
    }
};