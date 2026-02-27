    class Node {
        public :
            int data ;
            Node * next ;
            Node() : data(0) , next(nullptr) {};
            Node(int data): data(data) , next(nullptr) {};
    };


    class Solution {
    public:
        int findTheWinner(int n, int k) {
        // Create circular linked list
            Node* head = new Node(1);
            Node* temp = head;

            for(int i = 2; i <= n; i++){
                temp->next = new Node(i);
                temp = temp->next;
            }

            temp->next = head;   // make circular

            Node* curr = head;
            Node* prev = temp;   // last node initially

            while(curr->next != curr){   // until one node remains

                // move k-1 steps
                for(int i = 1; i < k; i++){
                    prev = curr;
                    curr = curr->next;
                }

                // remove curr
                prev->next = curr->next;
                curr = curr->next;
            }

            return curr->data;
        }
    };