class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string& word : words){
            int wordWeight = 0 ;
            for(char &ch: word){
                int index = ch - 'a';
                wordWeight += weights[index];
            }
            wordWeight = wordWeight % 26 ;
            char mappedChar = 'z' - wordWeight;
            ans += mappedChar;
        }

        return ans ;
    }
};