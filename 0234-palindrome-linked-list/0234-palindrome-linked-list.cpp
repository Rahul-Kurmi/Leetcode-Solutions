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
    
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head){
        if(head == nullptr) return head ;
        
        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        
        while(curr != nullptr){
            ListNode* forward = curr->next ;  
            curr->next = prev ;               
            prev = curr ;                     
            curr = forward;                   
        }
        return prev;  
    }

    bool isPalindrome(ListNode* head) {

        // If list is empty or single node → always palindrome
        if(head == nullptr || head->next == nullptr) 
            return true;

        ListNode * traverse = head ;
        ListNode * head2 = nullptr ;   // head of copied list
        ListNode * temp = nullptr ;    // pointer to build copied list

        // 🔹 Step 1: Create a copy of original list
        while(traverse != nullptr){

            // create new node with same value
            ListNode* newNode = new ListNode(traverse->val);

            // if first node
            if(head2 == nullptr){
                head2 = newNode;
                temp = newNode;
            }
            else{
                temp->next = newNode;  // attach new node
                temp = newNode;       // move temp forward
            }

            traverse = traverse->next;
        }

        // 🔹 Step 2: Reverse the copied list
        head2 = reverseList(head2);

        // 🔹 Step 3: Compare original and reversed copy
        while(head2 != nullptr){
            if(head2->val != head->val){
                return false ;  // mismatch found
            }
            head2 = head2->next ;
            head = head->next ;
        }

        return true ;  // all values matched
    }
};