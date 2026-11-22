//Approach-5 (Count 'a's, then verify prefix is all 'a')
//T.C : O(n)  (one pass to count + one pass to verify)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        int count_a = count(begin(s), end(s), 'a');
        
        // the first count_a characters must all be 'a'
        for (int i = 0; i < count_a; i++) {
            if (s[i] != 'a') 
                return false;
        }

        return true;
    }
};
