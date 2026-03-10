class Solution {
public:
    // By stack we acn also do that but most Competetive Programmer use this 
    bool isValid(string s) {
        string st ;
        for(auto ch : s){
            st +=ch ;
            if(st.size() >= 3 && st.substr(st.size() - 3) == "abc" ){
                // this will erase all elements after st.size() - 3
                // st.erase(st.size() - 3) ;
                st = st.substr(0 , st.size() - 3);
            }
        }
        return st.empty();   
    }
};