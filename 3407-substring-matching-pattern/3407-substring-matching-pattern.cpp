class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find('*');
        
        string str1 = p.substr(0, x);           // Before '*'
        string str2 = p.substr(x + 1);          // After '*' (simplified!)
        
        int findFirst = s.find(str1);
        
        // str1 not found
        if (findFirst == string::npos) {
            return false;
        }
        
        // Search for str2 AFTER str1 ends
        int searchFrom = findFirst + str1.length();
        
        return s.find(str2, searchFrom) != string::npos;
    }
};