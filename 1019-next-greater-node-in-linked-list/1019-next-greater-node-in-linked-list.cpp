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
    ListNode* reverseNode(ListNode* &head){
        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        ListNode* forward ;
        while(curr != nullptr){
            forward = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = forward ;
        }
        return prev ;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans ;
        head = reverseNode(head) ;
        stack<int> st ;
        while(head != nullptr){
            if(st.empty()){
                ans.push_back(0);
            }
            else{
                int val = head -> val ;
                while(!st.empty() && st.top() <= val){
                    st.pop();
                }

                st.empty() ? ans.push_back(0) : ans.push_back(st.top());
            }
            st.push(head -> val);
            head = head -> next ;
        }

        reverse(ans.begin() , ans.end());
        return ans;

    }
};