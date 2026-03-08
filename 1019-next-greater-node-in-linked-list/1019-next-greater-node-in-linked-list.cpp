/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        // Step 1: Store all linked list values in a vector
        // This allows us to access elements using indices
        vector<int> storeLL;
        while(head != nullptr){
            storeLL.push_back(head->val);
            head = head->next;
        }

        // Step 2: Initialize answer vector with 0
        // Default value is 0 because if no greater element exists,
        // the answer for that position should remain 0
        vector<int> ans(storeLL.size());

        // Stack will store indices of elements whose
        // next greater element has not been found yet
        stack<int> st;

        // Step 3: Traverse the array from left to right
        for(int i = 0; i < storeLL.size(); i++){

            // While stack is not empty and current value
            // is greater than the value at index stored in stack
            // we found the next greater element
            while(!st.empty() && storeLL[st.top()] < storeLL[i]){
                ans[st.top()] = storeLL[i];
                st.pop();
            }

            // Push current index to stack
            st.push(i);
        }

        // Step 4: Remaining indices in stack do not have
        // any next greater element, so their answer remains 0
        return ans;
    }
};