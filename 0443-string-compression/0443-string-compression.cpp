class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0 ;
        char prev = chars[0];
        int count = 1; 
        for(int i = 1 ; i < chars.size() ; i++){
            if(prev == chars[i]){
                count++;
            }
            else{
                chars[writeIndex++] = prev ;

                int start = writeIndex;
                if(count > 1){
                    while(count != 0){
                        int val = count % 10 ;
                        chars[writeIndex++] = val + '0';
                        count = count / 10 ;
                    }
                    reverse(chars.begin() + start , chars.begin() + writeIndex);
                }

                prev = chars[i];
                count = 1 ;
            }
        }

        chars[writeIndex++] = prev ;
        int start = writeIndex ;
        if(count > 1 ){
            while(count != 0){
                int val = count % 10 ;
                chars[writeIndex++] = val + '0'; 
                count /= 10;
            }
            reverse(chars.begin() + start , chars.begin() + writeIndex);
        }


        return writeIndex; 
    }
};