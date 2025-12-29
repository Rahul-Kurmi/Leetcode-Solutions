class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0 ;
        int i = 0 ;

        while(i < chars.size()){
            char ch = chars[i];
            int count = 1 ;
            while(i + 1 < chars.size() && ch == chars[i+1]){
                count++;
                i++;
            }
            i++;
            chars[writeIndex++] = ch ;
            if(count > 1){
                string countStr = to_string(count);
                for(auto it : countStr){
                    chars[writeIndex++] = it ;
                }
            }
        }

        return writeIndex ;
    }
};