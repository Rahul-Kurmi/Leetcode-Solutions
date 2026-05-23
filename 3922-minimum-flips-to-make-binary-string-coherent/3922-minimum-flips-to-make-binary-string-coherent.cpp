class Solution {
public:
    // possible cases to make 
    // 1. all 1 --> 111111
    // 2. all 0 --> 000000
    // 3. one 1 anywhere --> 100...00 or 000100 or 00..0001
    // 4. first & last 1 --> 1000.....0001


    // so for point 2 and 3 if we have multiple 1s then we'll try to make all 0 with one 1
    // so take --> oneCount - 1 as a possible solution

    int minFlips(string s) {
        if(s.size() == 1) return 0;
        int oneCount = 0 ;
        int zeroCount = 0;
        for(auto it : s){
            if(it == '1') oneCount++;
            else zeroCount++;
        }

        int ans = zeroCount ;
        if(oneCount){
            ans = min(ans , oneCount - 1);
        }

        int count = 0;
        if(s[0] == 0) count++;
        if(s[s.size() - 1] == 0) count++;
        for(int i = 1 ; i <= s.size() - 2 ; i++){
            if(s[i] == '1') count++;
        }

        ans = min(ans , count);

        return ans ;
    }
};