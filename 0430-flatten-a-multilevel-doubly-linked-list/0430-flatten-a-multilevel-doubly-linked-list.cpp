/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // Using Recursion going till last child and merging till first child 
        Node * curr = head ;
        while(curr != nullptr){
            if(curr -> child != nullptr){ // found curr's child
                Node* nextNode = curr -> next ;
                Node * childHead = flatten(curr -> child);

                curr -> next = childHead ;
                childHead -> prev = curr ;
                curr -> child = nullptr ;

                Node* childTail = childHead ;
                while(childTail -> next != nullptr){
                    childTail = childTail -> next ;
                }

                childTail -> next = nextNode ;
                if(nextNode != nullptr){ // if nextNode is not null
                    nextNode -> prev = childTail;
                }
            }   
            curr = curr -> next ;
        }

        return head ;
    }
};