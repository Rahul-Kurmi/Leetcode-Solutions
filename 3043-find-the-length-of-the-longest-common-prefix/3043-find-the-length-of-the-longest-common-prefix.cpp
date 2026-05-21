class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st; // store the prefix of every element in arr1
        
        // eg :- 1234 -> {1234, 123, 12, 1}
        for(auto val: arr1){
            // if val is not present and it's value is > 0 then insert in set
            while(!st.count(val) && val > 0){
                st.insert(val);
                val = val / 10 ;
            }
        }


        int result = 0 ; // Longest common Prefix
        for(auto val : arr2){
            // resduce val until it's present in set
            while(!st.count(val) && val > 0){
                val = val / 10 ;
            }

            // now this reduced val is in the set thus take it's length
            // length of a integer digit --> log10(num) + 1
            if(val > 0){
                result = max(result , (int)log10(val) + 1);
            }
        }
        return result ;
    }
};