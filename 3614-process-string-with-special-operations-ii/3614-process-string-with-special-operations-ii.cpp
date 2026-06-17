class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length() ;
        long long L = 0 ;

        // creating length L
        for(auto &ch: s){
            if(ch == '*'){ // pop L--
                if(L > 0) L--;
            }
            else if(ch == '#'){
                L = L * 2 ; // length become double
            }
            else if(ch == '%'){
                // L remians same --> no change
                continue;
            }
            else{ // ch is lowercase
                L++; 
            }
        }

        // if invalid query ie. k >= L
        if(k >= L) return '.'; 

        // Reverse Iterate ie. backtrack
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '*'){ // UNDO -> len++ , k same
                L++;
            }
            else if(s[i] == '%'){
                // no change in L , K = L - K - 1
                k = L - k - 1 ;
            }
            else if(s[i] == '#'){
                // k = k - L/2 , L = L/2 
                k = (k >= L/2) ? k - L/2 : k ;
                L = L/2 ;
            }
            else{ // char is lowercase
                L--;
            }

            // check if k == L
            if(k == L) return s[i];
        }

        return '.';

    }
};