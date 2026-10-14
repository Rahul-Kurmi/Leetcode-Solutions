class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        long long maxSum = 9 * num ;
        if(maxSum < sum ) return "";

        string ans = "";

        while(num--){
            if(sum >= 9){
                ans.push_back('9') ;
                sum -= 9 ;
            }
            else{
                ans.push_back('0' + sum) ;
                sum = 0 ;
            }
        }

        return ans;
    }
};