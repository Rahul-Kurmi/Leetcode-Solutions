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
    ListNode* merge(ListNode* headA, ListNode* headB){
        ListNode* dummy = new ListNode(-1);
        ListNode* ansNode = dummy ;
        while(headA && headB){
            if(headA -> val <= headB -> val){
                dummy -> next = headA ;
                headA = headA -> next ;
                dummy = dummy -> next ;
            }else{
                dummy -> next = headB ;
                headB = headB -> next ;
                dummy = dummy -> next ;
            }
        }

        if(headA){
            dummy -> next = headA ;
        }else{
            dummy -> next = headB ;
        }

        return ansNode -> next ;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr ;
        if(lists.size() == 1) return lists[0] ;
        ListNode* head = merge(lists[0] , lists[1]);
        for(int i = 2 ; i < lists.size() ; i++){
            head = merge(head , lists[i]);
        }
        return head ;
    }
};