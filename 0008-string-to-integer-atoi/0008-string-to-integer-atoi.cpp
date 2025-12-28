class Solution {
public:
    int myAtoi(string s) {
        int ans = 0 ;
        bool foundNum = false ;
        bool isNegative = false ;
        for(int i = 0 ; i < s.size() ; i++){
            if(foundNum && !isdigit(s[i])){
                break ;
            }
            if(s[i] == ' '){
                continue ;
            }
            else if(s[i] == '-'){
                isNegative = true ;
                foundNum = true;
            }
            else if(s[i] == '+'){
                isNegative = false ;
                foundNum = true;
            }
            else if(isdigit(s[i])){
                cout << ans << endl ;
                int digit = s[i] - '0';
                if (ans > (INT_MAX - digit) / 10) {
                    return isNegative ? INT_MIN : INT_MAX;
                }
                ans = ans * 10 + (s[i] - '0');
                foundNum = true ; 
            }else{
                break ;
            }
        }

        return (isNegative) ? -ans : ans ;
    }
};