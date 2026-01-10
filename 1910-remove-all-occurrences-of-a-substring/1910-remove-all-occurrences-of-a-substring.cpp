class Solution {
public:
    string removeOccurrences(string s, string part) {
        int found = s.find(part);
        if(found != string :: npos){
            string left_part = s.substr(0 , found);
            string right_part = s.substr(found + part.size() , s.size());
            s = left_part + right_part ;
            return removeOccurrences(s , part);
        }else{
            return s ;
        }
    }
};