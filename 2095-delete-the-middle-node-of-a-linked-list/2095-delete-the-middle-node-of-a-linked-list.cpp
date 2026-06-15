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
    ListNode* findMid(ListNode* head){
        ListNode* fast = head ;
        ListNode* slow = head ;

        while(fast != nullptr){
            fast = fast -> next ;
            if(fast != nullptr){
                fast = fast -> next ;
                slow = slow -> next ;
            }
        }

        return slow ;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == nullptr) return nullptr ;
        ListNode* mid = findMid(head);
        ListNode* midPrev = head ;
        while(midPrev -> next != mid){
            midPrev = midPrev -> next ;
        }

        midPrev -> next = mid -> next ;
        return head ;
    }
};