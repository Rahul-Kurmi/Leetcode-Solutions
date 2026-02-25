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
    int getLength(ListNode* head){
        int count = 0 ;
        while(head != nullptr){
            head = head -> next ;
            count++;
        }
        return count ;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head ;
        }

        int len = getLength(head);
        if(k > len){
            return head ;
        }

        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        ListNode* forward ;

        int i = 0 ;
        while(i < k){
            forward = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = forward ;
            i++;
        }

        if(forward != nullptr){
            head -> next = reverseKGroup(forward , k) ;
        }

        return prev ;
    }
};