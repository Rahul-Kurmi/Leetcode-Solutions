class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<double> prev(n+1 , 0); // Space Optimization onle one array

        // BASE CASES
        prev[0] = 1 ;

        for(int i = 1 ; i <= m ; i++){
            for(int j = n ; j >= 1 ; j--){
                double take = 0;
                // take current and check further 
                if(s[i-1] == t[j-1]) {
                    take = prev[j-1];
                }
                // skip current and check if any other matches
                double skip = prev[j];

                prev[j] = take + skip;
            }
        }

        return (int)prev[n];
    }
};