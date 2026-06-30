class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';  
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();

        // keep count of vowel in current window
        unordered_map<char , int> mp ; 

        // pre-processing to find index of just next consonant 
        vector<int> nextConsonant(n);
        int lastConIdx = n ;
        for(int i = n-1 ; i >= 0 ; i--){
            nextConsonant[i] = lastConIdx ;
            if(!isVowel(word[i])){
                lastConIdx = i ;
            }
        }

        int i = 0 ;
        int j = 0 ;
        long long count = 0 ;
        int consonant = 0 ;

        while(j < n ){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }
            else{
                consonant++;
            }

            // cont count must be always == k 
            while(consonant > k ){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    consonant--;
                }

                i++; // Window has more than k consonants, so move the left pointer to restore the constraint.
            }

            // valid winidow
            while(mp.size() == 5 && consonant == k){
                int idx = nextConsonant[j] ; // it will tell me the next consonat after jth index 
                count += idx - j ;  
                // now all valid substring from ith index found --> i++
                char ch = word[i];

                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    consonant--;
                }

                i++; 
            }

            // after while loop i will be incremented and whether map size < 5 of consonant not equal = k --> j++ ie. now find for curr i 
            j++; 
        }

        return count ;
    }
};