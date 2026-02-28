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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergeNode = new ListNode(-1);
        ListNode* head = mergeNode ;

        while(list1 != nullptr && list2 != nullptr){
            if(list1 -> val < list2 -> val){
                ListNode* temp = list1 ;
                list1 = list1 -> next ;
                mergeNode -> next = temp ;
                mergeNode = temp ; 
            }else{
                ListNode* temp = list2 ;
                list2 = list2 -> next ;
                mergeNode -> next = temp ;
                mergeNode = temp ; 
            }
        }

        if(list1 != nullptr){
            mergeNode -> next = list1 ;
        }

        if(list2 != nullptr){
            mergeNode -> next = list2 ;
        }

        return head -> next ;
    }
};