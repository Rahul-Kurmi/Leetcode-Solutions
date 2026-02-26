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
        if(head==NULL){
        // LL is empty 
        return head ;
         }
        if(head -> next == NULL){
            cout << "Single Node in LL " << endl ;
            return head ;
        }

        // LL contains greater then one node 
        ListNode * current = head ;
        while(current != NULL){
            if((current->next != NULL) && current -> val == current -> next -> val ){
                //temp creation to delete node
                ListNode*temp = current -> next ;
                //Equal 
                current -> next = current -> next -> next ;
                // Delete Node 
                temp -> next = NULL;
                delete temp;
            }
            else{
                // Not equal
                current = current -> next ;
            }
        }
        return head ;
    }
};