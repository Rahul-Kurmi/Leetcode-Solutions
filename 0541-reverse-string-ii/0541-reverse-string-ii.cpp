class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        string result = "";
        int i = 0;
        
        while(i < n){
            stack<char> st;
            
            // Push first k characters (or remaining) into stack
            int count = 0;
            while(count < k && i < n){
                st.push(s[i]);
                i++;
                count++;
            }
            
            // Pop from stack to reverse these characters
            while(!st.empty()){
                result += st.top();
                st.pop();
            }
            
            // Append next k characters as-is (no reversal)
            count = 0;
            while(count < k && i < n){
                result += s[i];
                i++;
                count++;
            }
        }
        
        return result;
    }
};