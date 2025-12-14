class Solution {
public:
    void reverse(string &s, int i, int j){
        while(i <= j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        
        while(i < n){
            int j = min(i + k - 1, n - 1);
            reverse(s, i, j);
            i += 2 * k;
        }
        
        return s;
    }
};