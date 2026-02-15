class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        char carry = '0';
        string ans = "";
        
        while(i >= 0 && j >= 0){
            if(a[i] == '1' && b[j] == '1' && carry == '1'){
                ans += '1';
                carry = '1';
            }
            else if(a[i] == '1' && b[j] == '1' && carry == '0'){
                ans += '0';
                carry = '1';
            }
            else if(a[i] == '0' && b[j] == '1' && carry == '1'){
                ans += '0';
                carry = '1';
            }
            else if(a[i] == '1' && b[j] == '0' && carry == '1'){
                ans += '0';
                carry = '1';
            }
            else if(a[i] == '0' && b[j] == '0' && carry == '1'){
                ans += '1';
                carry = '0';
            }
            // ✅ FIX: Add missing cases
            else if(a[i] == '1' && b[j] == '0' && carry == '0'){
                ans += '1';
            }
            else if(a[i] == '0' && b[j] == '1' && carry == '0'){
                ans += '1';
            }
            else{  // a[i]=='0' && b[j]=='0' && carry=='0'
                ans += '0';
            }
            i--;
            j--;
        }

        while(i >= 0){
            if(a[i] == '1' && carry == '0'){
                ans += '1';
            }
            else if(a[i] == '1' && carry == '1'){  // ✅ FIX: Changed from ans[i]
                ans += '0';
                carry = '1';
            }
            else if(a[i] == '0' && carry == '1'){
                ans += '1';
                carry = '0';
            }
            else{  // ✅ FIX: a[i]=='0' && carry=='0'
                ans += '0';
            }
            i--;
        }

        while(j >= 0){
            if(b[j] == '1' && carry == '0'){
                ans += '1';
            }
            else if(b[j] == '1' && carry == '1'){
                ans += '0';
                carry = '1';
            }
            else if(b[j] == '0' && carry == '1'){
                ans += '1';
                carry = '0';
            }
            else{  // ✅ FIX: b[j]=='0' && carry=='0'
                ans += '0';
            }
            j--;
        }

        if(carry == '1') ans += '1';

        reverse(ans.begin(), ans.end());  // ✅ FIX: Actually reverse
        return ans;
    }
};