class Solution {
public:
    int maxDepth(string s) {
        int depth = 0 ;
        int ans  = 0 ;

        for(auto ch : s){
            // if '(' encounter --> increase depth 
            if(ch == '('){
                depth++;
            }
            else if(ch == ')'){
                // decrese depth but first store ans 
                ans = max(ans , depth);
                depth--;
            }
        }

        return ans;
    }
};