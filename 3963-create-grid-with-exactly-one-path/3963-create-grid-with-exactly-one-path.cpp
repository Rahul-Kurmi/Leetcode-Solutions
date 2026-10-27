class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans ;
        string str1 = "";
        string str2 = "";
        for(int i = 0 ; i < n ; i++){
            str1 += '.';
            str2 += "#";
        }

        ans.push_back(str1);
        str2.pop_back();
        str2 += '.';

        for(int i = 1 ; i < m ; i++){
            ans.push_back(str2);
        }


        return ans ;
    }
};