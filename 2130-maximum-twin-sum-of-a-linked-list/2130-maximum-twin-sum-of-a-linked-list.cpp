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
    ListNode* getMiddle(ListNode* head){
        ListNode* fast = head ;
        ListNode* slow = head ;
        while(fast != nullptr){
            fast = fast -> next;
            if(fast != nullptr){
                fast = fast -> next ;
                slow = slow -> next ;
            }
        }

        return slow ;
    }

    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        ListNode* temp ;
        while(curr != nullptr){
            temp = curr -> next ;
            curr -> next = prev ;
            prev = curr;
            curr = temp;
        }

        return prev ;
    }

    int pairSum(ListNode* head) {
        ListNode* mid = getMiddle(head);
        mid = reverseLinkedList(mid);
        
        int maxPairSum = 0 ;
        while(mid != nullptr){
            int sum = mid -> val + head -> val ;
            head = head -> next ;
            mid = mid -> next ;
            maxPairSum = max(maxPairSum , sum);
        }

        return maxPairSum ;
    }
};