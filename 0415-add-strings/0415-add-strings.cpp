class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1 ;
        int j = num2.size() - 1 ;
        int carry = 0 ;
        string ans = "";
        while(i >= 0 && j >= 0){
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry ;
            int store = sum % 10 ;
            carry = sum / 10 ;
            ans.push_back(store + '0');
            i--;
            j--;
        }

        while(i >= 0){
            int sum = (num1[i] - '0') + carry;
            int store = sum % 10 ;
            carry = sum / 10 ;
            ans.push_back(store + '0');
            i--;
        }

        while(j >= 0){
            int sum = (num2[j] - '0') + carry;
            int store = sum % 10 ;
            carry = sum / 10 ;
            ans.push_back(store + '0');
            j--;
        }

        if(carry != 0){
            ans.push_back(carry + '0');
        }

        reverse(ans.begin() , ans.end());
        return ans ;
    }
};