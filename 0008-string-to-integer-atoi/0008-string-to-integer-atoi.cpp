class Solution {
public:
    int myAtoi(string s) {
        int ans = 0 ;
        int sign = 1 ;
        int n = s.size();
        int i = 0 ;
        while(i < n &&  s[i] == ' '){
            i++;
        }
        if(i < n && (s[i] == '-' || s[i] == '+')){
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        while(i < n && isdigit(s[i])){
            // num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7'
            if(ans > (INT_MAX - (s[i] - '0'))/10){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        return  sign == -1 ? -ans : ans ;
    }
};