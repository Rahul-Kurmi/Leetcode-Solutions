class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;   // 🔹 added edge case

        vector<string> store(numRows, "");
        int i = 0;
        bool isDown = true;
        int j = 0;

        while (i < s.size()) {        // 🔹 removed j condition

            store[j] += s[i++];
            
            // 🔹 direction change BEFORE going out of bounds
            if (j == numRows - 1)
                isDown = false;
            else if (j == 0)
                isDown = true;

            // 🔹 move row index
            j += isDown ? 1 : -1;
        }

        string ans = "";
        for (auto it : store) {
            ans += it;
        }

        return ans;
    }
};
