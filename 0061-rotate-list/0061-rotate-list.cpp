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
            count++;
            head = head -> next ;
        }
        return count ;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr) return head ;
        int len = getLength(head) ;

        k = k % len;
        if(k == 0) return head;

        ListNode* secondEnd = head ;
        int secondEndIndex = len - k ;
        int i = 1 ;
        while(i < secondEndIndex){
            secondEnd = secondEnd -> next ;
            i++;
        }

        ListNode* firstStart = secondEnd -> next ;
        secondEnd -> next = nullptr ;
        
        ListNode* firstEnd = firstStart ;
        while(firstEnd -> next != nullptr ){
            firstEnd = firstEnd -> next ;
        }

        firstEnd -> next = head ;
        return firstStart ;
    }
};