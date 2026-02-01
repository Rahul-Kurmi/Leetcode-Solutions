class Solution {
public:
    void solve(vector<string>& ans , int open , int close , string store){
        if(open == 0 && close == 0){
            ans.push_back(store);
            return ;
        }

        if(open > 0){
            store.push_back('(');
            solve(ans , open -1 , close , store);
            store.pop_back();
        }

        if(close > open){
            store.push_back(')');
            solve(ans , open , close - 1  , store);
            store.pop_back();
        }
        
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans ;        
        solve(ans,  n , n , "");
        return ans;
    }
};