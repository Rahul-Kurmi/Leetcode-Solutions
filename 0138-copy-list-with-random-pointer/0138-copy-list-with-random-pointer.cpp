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
        Node* temp = head ;
        while(temp != nullptr){
            Node* newNode = new Node(temp -> val);
            newNode -> next = temp -> next ;
            temp -> next = newNode ;
            temp = temp -> next -> next ; 
        }

        temp = head ;
        while(temp != nullptr){
            Node * copyNode = temp -> next ;
            if(temp -> random == nullptr) copyNode -> random = nullptr ;
            else{
                copyNode -> random = temp -> random -> next ;
            }
            temp = temp -> next -> next ;
        }

        temp = head ;
        Node* copyHead = temp -> next ;
        while(temp != nullptr){
            Node* copyNode = temp -> next ;
            temp -> next = copyNode -> next  ;
            temp = copyNode -> next ;
            if(temp != nullptr && temp -> next != nullptr){
                copyNode -> next = temp -> next ;
            }else{
                copyNode -> next = nullptr ;
            }
        }
        return copyHead ;
    }
};