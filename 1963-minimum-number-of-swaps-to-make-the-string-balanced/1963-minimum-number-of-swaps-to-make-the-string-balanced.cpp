class Solution {
public:
    int minSwaps(string s) {
       int size = 0  ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '['){
                size += 1 ;
            }
            else{
                if(size > 0){
                    size-- ;
                }
            }
        }
        return (size + 1) / 2;      
    }
};