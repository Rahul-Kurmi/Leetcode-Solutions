class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  
        vector<string> store(numRows , "") ;
        int i = 0 ;
        bool isDown = true ;
        int j  = 0 ;
        while(i < s.size() && j < numRows ){            
            while(isDown && i < s.size() ){
                if(j == numRows){
                    j = numRows-2 ;
                    isDown = false ;
                    break ;
                }
                store[j] += s[i];
                j++;
                i++;
            }
            while(!isDown && i < s.size() ){
                if(j == 0){
                    isDown = true ;
                    break;
                }
                store[j] += s[i];
                i++;
                j--;
            }
        }

        string ans = "";
        for(auto it : store){
            ans += it ;
        }

        return ans ;
    }
};