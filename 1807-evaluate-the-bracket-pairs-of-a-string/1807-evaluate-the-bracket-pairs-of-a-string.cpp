//Approach-2
//T.C : O(n+m) //TRaversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;

        for(auto &vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result = "";
        string temp = "";
        bool bracketOpened = false;
        int i = 0;
        
        while(i < n) {
            if(s[i] == '(') {
                bracketOpened = true;
            } else if(s[i] == ')') {
                result += mp.count(temp) ? mp[temp] : "?";
                bracketOpened = false;
                temp = "";
            } else if(bracketOpened) {
                temp.push_back(s[i]);
            } else {
                result.push_back(s[i]);
            }

            i++;
        }

        return result;
    }
};
