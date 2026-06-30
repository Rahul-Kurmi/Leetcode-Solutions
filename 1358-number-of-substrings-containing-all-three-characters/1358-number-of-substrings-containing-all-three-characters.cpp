class Solution {
public:
    // PRE-REQUISITE : LEETCODE - 3306
    bool isValidChar(char &ch){
        return ch == 'a' || ch == 'b' || ch == 'c';
    }

    int numberOfSubstrings(string word) {
        int n = word.size();

        unordered_map<char, int> mp ;

        int i = 0;
        int j = 0;
        int count = 0 ;

        while(j < n){
            char ch = word[j];
            if(isValidChar(ch)){
                mp[ch] ++ ;
            }

            while(mp.size() == 3){
                count += n - j ;

                char ch = word[i];
                i++;   
                if(isValidChar(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
            }

            j++;
        }

        return count ;
    }
};