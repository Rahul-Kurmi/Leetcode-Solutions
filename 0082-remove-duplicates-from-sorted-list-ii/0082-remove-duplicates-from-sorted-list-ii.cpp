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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;   // last confirmed unique node
        ListNode* curr = head;

        while(curr != nullptr){

            // If duplicate sequence found
            if(curr->next != nullptr && curr->val == curr->next->val){

                int duplicateValue = curr->val;

                // skip all nodes with same value
                while(curr != nullptr && curr->val == duplicateValue){
                    curr = curr->next;
                }

                prev->next = curr;  // remove duplicates
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};