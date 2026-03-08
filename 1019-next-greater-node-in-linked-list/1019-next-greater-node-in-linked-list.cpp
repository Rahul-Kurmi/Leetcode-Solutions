class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> storeLL;
        while(head != nullptr){
            storeLL.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        for(int i = 0; i < storeLL.size(); i++){
            while(!st.empty() && storeLL[st.top()] < storeLL[i]){
                storeLL[st.top()] = storeLL[i];
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            storeLL[st.top()] = 0 ;
            st.pop();
        }

        return storeLL;
    }
};