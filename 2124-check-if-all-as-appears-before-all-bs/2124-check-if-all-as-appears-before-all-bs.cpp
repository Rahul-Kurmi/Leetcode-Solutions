//Approach-2 (Track last 'a' and first 'b' indices)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        int n = s.length();

        int first_b = -1;
        int last_a  = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                last_a = i;
            } else if(first_b == -1) {
                first_b = i;
            }
        }

        if(first_b == -1 || last_a == -1)
            return true;
        
        return last_a < first_b;
    }
};