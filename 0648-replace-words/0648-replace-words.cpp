class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, bool> mp;
        for(auto &it : dictionary){
            mp[it] = true;
        }

        string ans = "";
        int i = 0, j = 0;

        while(j < sentence.size()){
            if(sentence[j] == ' '){
                string str = sentence.substr(i, j - i);

                string m = "";
                bool isFound = false;

                for(int k = 0; k < str.size(); k++){
                    m += str[k];
                    if(mp.find(m) != mp.end()){
                        ans += m;
                        isFound = true;
                        break;
                    }
                }

                if(!isFound){
                    ans += str;
                }

                ans += " "; // add space

                i = j + 1;
            }
            j++;
        }

        // last word
        string str = sentence.substr(i);

        string m = "";
        bool isFound = false;

        for(int k = 0; k < str.size(); k++){
            m += str[k];
            if(mp.find(m) != mp.end()){
                ans += m;
                isFound = true;
                break;
            }
        }

        if(!isFound){
            ans += str;
        }

        return ans;
    }
};