class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int found = s.find(part);
            if(found != string::npos){
                string left_part = s.substr(0 , found);
                string right_part = s.substr(found + part.size() , s.size());
                s = left_part + right_part ;
            }else{
                break ;
            }
        }
        return s ; 
    }
};