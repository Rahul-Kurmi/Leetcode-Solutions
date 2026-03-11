class Solution {
public:
    string decodeString(string s) {
        stack<string> st ;
        for(auto ch : s){
            if(ch == ']'){
                string temp = "" ;
                while(!st.empty() && st.top() != "["){
                    temp += st.top() ; 
                    st.pop();
                }
                // remove top of stack as "["
                st.pop() ;

                string stringNum = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    stringNum += st.top() ;
                    st.pop() ;
                }

                // Reverse the stringNum to get actual integer 
                reverse(stringNum.begin() , stringNum.end());

                int num = stoi(stringNum) ;

                string decodedString = "" ;
                while(num--){
                    decodedString += temp;
                }
                st.push(decodedString) ;
            }else{
                // as ch is character and st stores string thus convert it into string
                // here string is a class which take 2 paremeters 
                // first -> size_t how many times repeat the char 
                // the char value we are converting to string 
                // string temp (1, ch) ;
                string temp = string(1 , ch) ;
                st.push(temp) ;
            }
        }

        string ans = "" ;
        while(!st.empty()){
            ans += st.top() ;
            st.pop() ;
        }

        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};