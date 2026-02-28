/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA ;
        ListNode* b = headB ;
        while(a -> next != nullptr && b -> next != nullptr){
            if(a == b){
                return a ;
            }

            a = a -> next ;
            b = b -> next ;
        }

        if(a -> next == nullptr){
            // b LL is bigger or equal 
            // we have to find how much bigger 
            int blen = 0 ;
            while(b -> next != nullptr){
                blen++;
                b = b -> next ;
            }

            // Now Move headB blen times so that headA and haedB meet at same position
            while(blen){
                headB = headB -> next;
                blen--;
            }
        }

        // a LL is bigger
        if(b -> next == nullptr){
            int  alen = 0 ;
            while(a -> next != nullptr){
                alen++;
                a = a -> next ;
            }

            //Now move headA alen times so that headA and headB can meet at same position
            while(alen){
                headA = headA -> next ;
                alen--; 
            }
        }

        while(headA != nullptr && headB != nullptr){
            if(headA == headB){
                return headA ;
            }
            headA = headA -> next ;
            headB = headB -> next ;
        }

        return nullptr ;
    }
};