class Solution {
public:
    vector<int> nextSmallerIndex(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n) ;
        stack<int> st ;
        for(int i = arr.size() - 1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop() ;
            }

            ans[i] = st.empty() ? n : st.top(); // storing Index
            st.push(i) ; 
        }
        return ans ;
    }

    vector<int> prevSmallerIndex(vector<int> arr){
        int n = arr.size() ;
        vector<int> ans(n) ;
        stack<int> st ;
        for(int i = 0 ; i < arr.size() ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop() ;
            }

            ans[i] = st.empty() ? -1 : st.top() ; // storing Index 
            st.push(i);
        }
        return ans ;
    }

    int maxHistograArea(vector<int> heights){
        int n = heights.size() ;
        vector<int> left = prevSmallerIndex(heights);
        vector<int> right = nextSmallerIndex(heights);

        int maxArea = 0;

        for(int i = 0 ; i < n ; i++){
            int width = right[i] - left[i] - 1 ;
            int area = width * heights[i] ;
            maxArea = max(area , maxArea);
        }

        return maxArea ;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int colSize = matrix[0].size();
        vector<int> curr(colSize , 0);
        int maximumArea = 0 ;
        for(int i = 0 ; i < matrix.size() ; i++){
            vector<char> temp = matrix[i] ;
            if(i == 0){
                for(int r1 = 0 ; r1 < colSize ; r1++){
                    char ch = temp[r1];
                    int val = ch - '0' ;
                    curr[r1] = val ;
                }
            }
            else{
                for(int rn = 0 ; rn < colSize ; rn++){
                    char ch = temp[rn];
                    int val = ch - '0' ;
                    if(val == 0){
                        curr[rn] = 0 ;
                    }
                    else{
                        curr[rn] += val ;
                    }
                }
            }

            int histArea = maxHistograArea(curr);
            maximumArea = max(maximumArea , histArea); 
        }
        return maximumArea;
    }
};