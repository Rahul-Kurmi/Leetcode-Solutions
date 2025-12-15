class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanPairs = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string ans = "";
        for(auto it : romanPairs) {
            int ele = it.first;
            while(num != 0 && num >= ele) {
                ans += it.second;
                num = num - ele;
            }
        }
        return ans;
    }
};