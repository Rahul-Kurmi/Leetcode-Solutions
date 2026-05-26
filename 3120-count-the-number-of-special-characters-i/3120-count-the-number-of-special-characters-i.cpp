//Approach-3 (One Pass Frequency Count)
//T.C : O(n) 1 Pass
//S.C : O(1)  fixed size array of 123
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq[123] = {0};
        int count = 0;

        for(char ch : word) {
            freq[ch]++;

            // Current ch is lower case , then look for upper case
            if(ch >= 'a' && ch <= 'z') {
                char capital = ch - 'a' + 'A';
                if(freq[ch] == 1 && freq[capital] > 0) // lowercase just appeared for first time
                    count++;
            } else { // Current ch is upper case , then look for lower case
                char lower = ch - 'A' + 'a';
                if(freq[ch] == 1 && freq[lower] > 0) // uppercase just appeared for first time
                    count++;
            }
        }

        return count;
    }
};