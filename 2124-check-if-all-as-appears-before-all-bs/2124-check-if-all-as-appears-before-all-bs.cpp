//Approach-3 (Substring search for "ba")
//T.C : O(n)  (the pattern has constant length 2)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};
