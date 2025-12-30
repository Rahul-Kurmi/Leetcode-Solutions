class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;   // edge case

        vector<string> store(numRows, "");
        int i = 0;
        bool isDown = true;
        int j = 0;

        while (i < s.size()) {

            // moving down
            while (isDown && i < s.size()) {
                store[j] += s[i++];
                if (j == numRows - 1) {
                    isDown = false;
                    j--;              // step back into range
                    break;
                }
                j++;
            }

            // moving up
            while (!isDown && i < s.size()) {
                store[j] += s[i++];
                if (j == 0) {
                    isDown = true;
                    j++;              // step forward into range
                    break;
                }
                j--;
            }
        }

        string ans = "";
        for (auto &it : store) {
            ans += it;
        }

        return ans;
    }
};
