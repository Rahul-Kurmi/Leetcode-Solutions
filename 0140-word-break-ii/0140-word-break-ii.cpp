class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> mp ; // map for Memoization
    
    vector<string> solve(string &s, int start){
        if(start == s.size()){
            return {""}; // empty string vector  
        }

        if(mp.find(start) != mp.end()){
            return mp[start];
        }

        vector<string> ans ;
        string word = "";

        for(int i = start ; i < s.size() ; i++){
            word += s[i] ;
            if(dict.find(word) != dict.end()){
                vector<string> rightPart = solve(s, i+1);
                for(auto endRightPart : rightPart){
                    string endPart ;
                    if(endRightPart.size() > 0){
                        endPart = " " + endRightPart;
                    }

                    ans.push_back(word + endPart);
                }
            }
        }

        return  mp[start] = ans ;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) {
            dict.insert(word);
        }

        return solve(s, 0);
    }
};