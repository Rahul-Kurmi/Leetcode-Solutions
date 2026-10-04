// USING STACK 
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st ;
        stack<int> stars ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{ // st is empty no maching pair --> check if we have stars
                    if(stars.empty()) return false ; // no mathing '(' for ')'
                    else stars.pop();
                }
            }
            else{ // push '*' in stars stack
                stars.push(i);
            }
        }


        while(!st.empty()){
            // if no stars --> means can't get matching return false
            if(stars.empty()) return false ;

            // means we have remaining '(' in the stack
            if(stars.top() > st.top()){
                // means star came after '(' --> we can match
                st.pop();
                stars.pop();
            }
            else return false ;
        }
        
        return true ;

    }
};