//(Using Bottom Up)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public: 
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
        //State Definition :
        //t[i][j] = if the string from index i to n-1 is valid or not having j count brackets
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int count = n; count >=0; count--) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= t[i + 1][count + 1]; //Treating * as ( --> solve(i+1, count+1)
                    if (count > 0) {
                        isValid |= t[i + 1][count - 1]; //Treating * as ) --> solve(i+1, count-1)
                    }
                    isValid |= t[i + 1][count]; //Treating * as empty --> solve(i+1, count)
                } else {
                    if (s[i] == '(') {
                        isValid |= t[i + 1][count + 1]; //solve(i+1, count+1)
                    } else if (count > 0) {
                        isValid |= t[i + 1][count - 1]; //solve(i+1, count=-1)
                    }
                }
                t[i][count] = isValid;
            }
        }

        return t[0][0];
    }
};
