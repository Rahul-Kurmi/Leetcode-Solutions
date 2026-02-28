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
        if(head == nullptr) return nullptr;

        // Step 1: Count frequency
        unordered_map<int,int> mp;
        ListNode* temp = head;
        while(temp != nullptr){
            mp[temp->val]++;
            temp = temp->next;
        }

        // Step 2: Remove nodes with freq > 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        temp = head;

        while(temp != nullptr){
            if(mp[temp->val] > 1){
                prev->next = temp->next;   // remove node
            } else {
                prev = temp;              // keep node
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};