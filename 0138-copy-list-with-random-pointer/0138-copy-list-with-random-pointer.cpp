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
    Node* deepCopy(Node* head, unordered_map<Node* , Node*>& mp){
        if(head == nullptr) return head;
        Node* newNode = new Node(head -> val);
        mp[head] = newNode ;
        newNode -> next = deepCopy(head -> next , mp);
        newNode -> random = mp[head -> random];
        return newNode ; 
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node* > mp;
        return deepCopy(head , mp);
    }
};