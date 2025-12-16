class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s.size() <= 1 ) return s.size() ;
        int ans = 0 ;
        int maxLen = 1 ;
        int i = 0 ;
        int j = 1 ;
        while(j < s.size()){
            if((s[i] - '0') + 1 == (s[j] - '0')){
                maxLen += 1; 
                j++; 
                i++;
            }else{
                maxLen = 1 ;
                i = j ;
                j++;
            }
            ans = max(ans , maxLen);
        }
        return ans;
    }
};