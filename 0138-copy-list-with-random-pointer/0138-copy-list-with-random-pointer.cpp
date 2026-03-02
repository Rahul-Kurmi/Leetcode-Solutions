/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head ;

        // STEP 1 : Clone A -> A' 
        Node* temp = head ;
        while(temp != nullptr){
            Node* newNode = new Node(temp -> val);
            newNode -> next = temp -> next ;
            temp -> next = newNode ;
            temp = temp -> next -> next ; 
        }

        // STEP 2 : Assign random links of A' with the help of old Nodes (A)
        temp = head ;
        while(temp != nullptr){
            Node * copyNode = temp -> next ;
            if(temp -> random == nullptr) copyNode -> random = nullptr ;
            else{
                copyNode -> random = temp -> random -> next ;
            }
            temp = temp -> next -> next ;
        }

        // STEP 3 : Detach A' from A
        temp = head ;
        Node* copyHead = temp -> next ;
        while(temp != nullptr){
           Node* copyNode = temp -> next ;
           temp -> next = temp -> next -> next ;
           if(copyNode -> next != nullptr){
            copyNode -> next = copyNode -> next -> next ;
           }
           temp = temp -> next ;
        }
        return copyHead ;
    }
};