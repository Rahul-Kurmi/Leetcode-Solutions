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
        Node * curr = head ;
        while(curr != nullptr){
            if(curr -> child != nullptr){
                Node* nextNode = curr -> next ;
                Node* childNode = curr -> child ;

                // find tail of child list
                Node* childTail = childNode ;
                while(childTail -> next != nullptr){
                    childTail = childTail -> next ;
                }

                // connect tail with curr->next
                childTail -> next = nextNode ;
                if(nextNode != nullptr){
                    nextNode -> prev = childTail ;
                }

                // connect curr with child
                curr -> next = childNode ;
                curr -> child = nullptr ;
                childNode -> prev = curr ;
            }
            curr = curr -> next ;
        }

        return head ;
    }
};