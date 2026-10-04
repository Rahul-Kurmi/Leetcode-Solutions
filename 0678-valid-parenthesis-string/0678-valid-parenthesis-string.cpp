class Solution {
public:
    int dp[101][101];

    bool solve(string &s, int i, int count){

        if(i == s.size()){
            return count == 0;
        }

        // Already calculated this state
        if(dp[i][count] != -1){
            return dp[i][count];
        }

        bool ifOpen = false;

        if(s[i] == '('){
            ifOpen = solve(s, i+1, count+1);
        }

        bool ifClose = false;

        if(s[i] == ')' && count > 0){
            ifClose = solve(s, i+1, count-1);
        }

        bool ifStar = false;

        if(s[i] == '*'){

            // '*' -> '('
            bool takeOpen = solve(s, i+1, count+1);

            // '*' -> ')'
            bool takeClose = false;

            if(count > 0){
                takeClose = solve(s, i+1, count-1);
            }

            // '*' -> empty
            bool skip = solve(s, i+1, count);

            ifStar = takeOpen || takeClose || skip;
        }

        return dp[i][count] = ifOpen || ifClose || ifStar;
    }

    bool checkValidString(string s) {

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 0);
    }
};