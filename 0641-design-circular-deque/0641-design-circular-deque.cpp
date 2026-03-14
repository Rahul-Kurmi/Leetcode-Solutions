class MyCircularDeque {
public:
    int *arr ;
    int front ;
    int rear ;
    int size ;
    MyCircularDeque(int k) {
        arr = new int[k] ;
        this -> size = k ;
        front = -1 ;
        rear = -1 ;
    }
    
    bool insertFront(int value) {
        if((front == 0 && rear == size - 1) || (rear == front - 1)){
            return false;
        }

        // One Element 
        else if(front == -1){
            front++;
            arr[front] = value ;
            rear = front ;
        }

        // front at zero 
        else if(front == 0){
            front = size - 1;
            arr[front] = value ;
        }

        // Rest front positions  
        else{
            front--;
            arr[front] = value ;
        }

        return true ;
    }
    
    bool insertLast(int value) {
        if((front == 0 && rear == size -1 ) || (rear == front - 1)){
            return false ;
        }

        // Empty Case 
        else if(front == -1){
            front++;
            arr[front] = value ;
            rear = front;
        }

        // if rear == size - 1
        else if(rear == size - 1){
            rear = 0 ;
            arr[rear] = value ;
        }

        // rest case 
        else{
            rear++;
            arr[rear] = value ;
        }

        return true ;
    }
    
    bool deleteFront() {
        if(front == -1) return false ;
        else if(front == rear){
            // only one element in queue 
            arr[front] = -1 ;
            front = -1 ;
            rear = -1;
        }
        else if(front == size - 1){
            arr[front] = -1 ;
            front = 0 ;
        }
        else{
            arr[front] = -1;
            front++;
        }
        return true ;
    }
    
    bool deleteLast() {
        if(front == -1) return false ;
        else if(front == rear){
            // only one element in queue 
            arr[front] = -1 ;
            front = -1 ;
            rear = -1;
        }
        else if(rear == 0){
            arr[rear] = -1 ;
            rear = size - 1; 
        }
        else{
            arr[rear] = -1;
            rear-- ;
        }
        return true ;
    }
    
    int getFront() {
        if(front == -1) return -1 ;
        return arr[front];
    }
    
    int getRear() {
        if(front == -1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1 ;
    }
    
    bool isFull() {
        if(front == 0 && rear == size - 1) return true ;
        else if(rear == front - 1) return true ;
        return false ;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */