class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1 ;
        int j = b.size() - 1 ;
        int carry = 0 ;

        string ans = "" ;

        while(i >= 0 && j >= 0){
            int sum = (a[i] - '0') + (b[j] - '0') + carry ;
            
            char to_store = (sum % 2) + '0';
            ans += to_store ;
            carry = sum / 2 ;
            i--;
            j--;
        }

        while(i >= 0){
            int sum = (a[i] - '0') + carry ;
            char to_store = (sum % 2) + '0';
            ans += to_store ;
            carry = sum / 2 ;
            i--;
        }

        while(j >= 0){
            int sum = (b[j] - '0') + carry ;
            char to_store= (sum % 2) + '0' ;
            ans += to_store ;
            carry = sum / 2; 
            j--;
        }

        if(carry != 0){
            ans += carry + '0'; 
        }

        reverse(ans.begin() , ans.end());
        return ans ;
    }
};