class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int> freqMap ;
        for(int i = 0 ; i < s.size() ; i++){
            freqMap[s[i]]++;
        }

        int highFreq = 0 ;
        char highChar ;
        for(auto it : freqMap){
            if(it.second  > highFreq){
                highFreq = it.second;
                highChar = it.first ;
            }
        }

        int i = 0 ;
        while(i < s.size() && highFreq != 0){
            s[i] = highChar ;
            highFreq--;
            freqMap[highChar] = highFreq ;
            i = i + 2;  
        }

        if(highFreq != 0) return "";

        for(auto &it : freqMap){
            while(it.second > 0 && i < s.size()){
                s[i] = it.first ;
                it.second--;
                i += 2 ;
            }
        }

        int j = 1 ;
         for(auto &it : freqMap){
            while(it.second > 0 && j < s.size()){
                s[j] = it.first ;
                it.second--;
                j += 2 ;
            }
        }
        return s ;
    }
};