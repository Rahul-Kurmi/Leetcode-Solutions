//Approach-2 (Frequency Count using char iteration)
//T.C : O(n) 2 Pass
//S.C : O(1)  fixed size array of 123
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq[123] = {0};

        for(char ch : word) {
            freq[ch]++;
        }

        int count = 0;
        //ASCII : a : 97 , b = 98 ..... 122 : z
        //ASCII : A : 65,  B = 66 ..... 90  : Z

        for(char ch = 'a'; ch <= 'z'; ch++) { //Iterate from 97 to 122 or 'a' to 'z'
            char capital = ch - 'a' + 'A'; //A... Z

            if(freq[ch] > 0 && freq[capital] > 0) //Both should be present
                count++;
        }

        return count;
    }
};