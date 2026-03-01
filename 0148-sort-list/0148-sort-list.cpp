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
        ListNode* slow = head ;
        ListNode* fast = head -> next ;
        while(fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next ;
            slow = slow -> next ;
        }
        return slow ;
    }

    ListNode* merge(ListNode* left , ListNode* right){
        ListNode* mergedNode = new ListNode(-1);
        ListNode* head = mergedNode ;

        while(left != nullptr && right != nullptr){
            if(left -> val < right -> val ){
                mergedNode -> next = left ;
                mergedNode = left ;
                left = left -> next;
            }else{
                mergedNode -> next = right ;
                mergedNode = right ;
                right = right -> next ; 
            }
        }

        if(left != nullptr){
            mergedNode -> next = left ;
        }

        if(right != nullptr){
            mergedNode -> next = right ;
        }

        return head -> next ;
    } 

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head ;
        }

        ListNode* mid = findMid(head);
        ListNode* left = head ;
        ListNode* right = mid -> next ;
        // In left LL make last node point to null for merge
        mid -> next = nullptr ;

        left = sortList(left);
        right = sortList(right);

        ListNode* mergedLL = merge(left , right);
        return mergedLL ;
    }
};