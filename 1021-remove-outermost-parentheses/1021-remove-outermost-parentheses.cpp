class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "" ;
        int open = 0 ;
        for(auto it : s){
            if(it == '('){
                if(open > 0 ) ans+='(';
                open++;
            }
            else{
                open--;
                if(open > 0) ans+= ')';
            }
        }
        return ans ;
    }
};