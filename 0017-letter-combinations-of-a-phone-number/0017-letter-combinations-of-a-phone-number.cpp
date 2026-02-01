class Solution {
public:
    void solve(string& digits , unordered_map<int , string> &mp , int i , vector<string>& ans , string store){
        if(i >= digits.size()){
            ans.push_back(store);
            return ;
        }

        int val = digits[i] - '0';
        string iterateOn = mp[val];
        for(int k = 0 ; k < iterateOn.size() ; k++){
            solve(digits , mp , i+1 , ans, store + iterateOn[k]);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int , string> mp {
            {2 , "abc"},
            {3 , "def"},
            {4 , "ghi"},
            {5 ,  "jkl"},
            {6 , "mno"},
            {7 , "pqrs"},
            {8 , "tuv"},
            {9 , "wxyz"}
        };
        vector<string> ans ;
        solve(digits , mp , 0 , ans , "");
        return ans ;
    }
};