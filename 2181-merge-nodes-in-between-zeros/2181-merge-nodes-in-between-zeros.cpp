class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        ListNode* temp = head->next;  // skip first 0
        int sum = 0;
        
        while(temp != nullptr){
            if(temp->val == 0){
                curr->next = new ListNode(sum);  // store sum
                curr = curr->next;
                sum = 0;                          // reset
            } else {
                sum += temp->val;                 // accumulate
            }
            temp = temp->next;                    // ✅ move forward
        }
        
        return dummy->next;
    }
};