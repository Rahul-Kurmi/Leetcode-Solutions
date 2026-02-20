class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string store = "" ;
        for(int i  = 0 ; i < words.size() ; i++){
            store += words[i];
            if(store.length() == s.length()){
                string sub = store.substr(0 , s.length());
                if(sub == s){
                    return true ;
                }
                else{
                    return false ;
                }
            }
        }
        return false ;
    }
};