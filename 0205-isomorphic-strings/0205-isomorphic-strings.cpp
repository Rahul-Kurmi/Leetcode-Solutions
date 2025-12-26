class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sHash[256] = {0};
        int isTMarked[246] = {0};
        
        for(int i = 0 ; i < s.size() ; i++){
            if(sHash[s[i]] == 0  && isTMarked[t[i]] == 0){
                sHash[s[i]] = t[i];
                isTMarked[t[i]] = 1 ;
            }
        }

        for(int i = 0 ; i < s.size() ; i++){
            if(sHash[s[i]] != t[i]) return false ;
        }

        return true ;
    }
};