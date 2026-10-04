class Solution {
public:
    int dp[101][101][101];

    bool solve(string& s, int i, int open, int close){

        if(i == s.size()){
            return open == close;
        }

        if(dp[i][open][close] != -1){
            return dp[i][open][close];
        }

        bool ifOpen = false;

        if(s[i] == '('){
            ifOpen = solve(s, i+1, open+1, close);
        }

        bool ifClose = false;

        if(s[i] == ')' && open > close){
            ifClose = solve(s, i+1, open, close+1);
        }

        bool isStar = false;

        if(s[i] == '*'){

            // '*' -> '('
            bool takeOpen = solve(s, i+1, open+1, close);

            // '*' -> ')'
            bool takeClose = false;

            if(open > close){
                takeClose = solve(s, i+1, open, close+1);
            }

            // '*' -> empty
            bool skip = solve(s, i+1, open, close);

            isStar = takeOpen || takeClose || skip;
        }

        bool ans = ifOpen || ifClose || isStar;

        return dp[i][open][close] = ans;
    }

    bool checkValidString(string s) {

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 0, 0);
    }
};