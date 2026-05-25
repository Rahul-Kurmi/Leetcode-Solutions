class Solution {
public:
    int minInsertions(string s) {
        string t = s ;
        reverse(t.begin() , t.end());
        int n = s.size();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);

        // BASE CASE
        for(int i = 0 ; i <= n ; i++) prev[i] = 0;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                int result = 0 ;
                if(s[i - 1] == t[j - 1]){
                    result = 1 + prev[j-1];
                }
                else{
                    result = max(curr[j-1] , prev[j]);
                }

                curr[j] =  result ;
            }
            prev = curr ;
        }


        int longPallSubsequence = prev[n];
        return n - longPallSubsequence ;
    }
};