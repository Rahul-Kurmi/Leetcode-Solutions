//Approach-4 (Check if string is sorted)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        return is_sorted(begin(s), end(s));
    }
};