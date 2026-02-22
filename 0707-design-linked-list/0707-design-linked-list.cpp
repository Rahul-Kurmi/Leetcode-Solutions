class Node {
    public :
        int val ;
        Node * next ;
        Node(int d) : val(d) , next(nullptr) {}
};


class MyLinkedList {

private :
    Node * head ;
    int size ;
public:
    MyLinkedList() {
        head = nullptr ;
        size = 0 ;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1 ;
        Node * temp = head ;
        int i = 0; 
        while(i != index){
            temp = temp -> next ;
            i++ ;
        }
        return temp -> val;
    }
    
    void addAtHead(int val) {
        Node * temp = new Node(val);
        temp -> next = head ;
        head = temp ;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            size++;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) { addAtHead(val); return; }
        if (index == size) { addAtTail(val); return; }

        int i = 0;
        Node * prev = head ;
        while(i < index - 1){
            prev = prev -> next ;
            i++;
        }
        Node * temp = new Node(val) ;
        temp -> next = prev-> next ;
        prev-> next = temp ;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            int i = 0 ;
            Node * prev = head ;
            while(i < index - 1){
                prev = prev -> next ;
                i++;
            }
            Node * deleteNode = prev -> next ;
            prev -> next = deleteNode -> next ;
            delete deleteNode ;
        }   
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */