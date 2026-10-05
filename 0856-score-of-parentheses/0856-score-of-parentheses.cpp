class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0 ;
        int score = 0 ;

        for(int i = 0; i < (int)s.size() ; i++){
            if(s[i] == '('){
                depth++;
            }
            else{
                depth--;
                if(s[i-1] == '('){
                    score += 1 << depth ; // add prev score + pow(2, depth-1);
                }
            }
        }

        return score ;
    }
};