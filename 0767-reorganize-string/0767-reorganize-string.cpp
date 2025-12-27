class Solution {
public:
    string reorganizeString(string s) {
        int freqHash[26] = {0};
        for(int i = 0 ; i < s.size() ; i++){
            freqHash[s[i] - 'a']++;
        }

        int highFreq = 0 ;
        char highChar ;
        for(int i = 0 ; i < 26  ; i++){
            if(freqHash[i] > highFreq){
                highFreq = freqHash[i];
                highChar = i + 'a';
            }
        }

        int i = 0 ;
        while(i < s.size() && highFreq > 0 ){
            s[i] = highChar ;
            i += 2;
            highFreq--;
        }

        if(highFreq != 0) return "";
        freqHash[highChar - 'a'] = 0;

        for(int j = 0 ; j < 26 ; j++){
            while(freqHash[j] > 0){
                (i < s.size()) ? i = i : i = 1 ;
                s[i] = j + 'a';
                freqHash[j]--;
                i += 2 ;
            }
        }
        return s ;
    }
};