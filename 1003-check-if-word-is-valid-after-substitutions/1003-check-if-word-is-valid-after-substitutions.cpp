    class Solution {
    public:
        bool isValid(string &s) {
            if(s == "") return true ;
            int index = s.find("abc");

            if(s.find("abc") != string::npos){
                string left = s.substr(0 , index) ;
                string right = s.substr(index + 3) ;
                string newStr = left + right;
                if(isValid(newStr)) return true ;
            }

            return false ;
        }
    };