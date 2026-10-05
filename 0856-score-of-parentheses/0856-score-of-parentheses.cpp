class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        vector<int> vec ;

        int score = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                vec.push_back(score);
                score = 0 ;
            }
            else{ // for ')'
                if(s[i-1] == '('){ // got most inside pair
                    score = vec.back() + 1 ;
                }
                else{ // found ')' ie forming )) --> multiply curr score by 2 and add prev score
                    score = vec.back() + score*2 ;
                }
                
                vec.pop_back(); // remove this added score
            }
        } 
        return score;
    }
};