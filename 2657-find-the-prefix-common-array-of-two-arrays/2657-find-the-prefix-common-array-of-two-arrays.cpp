class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> st ;
        vector<int> ans(A.size()) ;
        for(int i = 0 ; i < B.size(); i++){
            int foundVal = 0;
            st.insert(A[i]);
            for(int j = 0; j <= i ; j++){
                if(st.count(B[j])) foundVal++;
            }
            ans[i] = foundVal;
        }
        return ans ;
    }
};