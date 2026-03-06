class Solution {
public:

    vector<int> nextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> next(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return next;
    }

    vector<int> prevSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prev;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> left = prevSmaller(heights);
        vector<int> right = nextSmaller(heights);

        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
};