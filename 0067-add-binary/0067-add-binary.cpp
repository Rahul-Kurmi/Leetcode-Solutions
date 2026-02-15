class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;  // ✅ Use int instead of char
        string ans = "";
        
        // Process both strings from right to left
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if(i >= 0) {
                sum += a[i] - '0';  // Convert char to int
                i--;
            }
            
            if(j >= 0) {
                sum += b[j] - '0';  // Convert char to int
                j--;
            }
            
            ans += (sum % 2) + '0';  // Append current bit
            carry = sum / 2;          // Calculate carry
        }
        
        // Reverse the result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};