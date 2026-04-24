class Solution {
public:

    bool camelMatchHelper(string word , string pattern){
        int i = 0 ;
        int j = 0 ;
        while(i < word.size()){
            if(word[i] == pattern[j]){
                i++;
                j++;
            }
            else if(islower(word[i])){
                i++;
            }
            else{
                return false;
            }
        }

        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans ;
        for(auto word : queries){
            ans.push_back(camelMatchHelper(word , pattern));
        }
        return ans;
    }
};