class MyCircularQueue {
public:
    int* arr ;
    int size ;
    int front ;
    int rear ;
    MyCircularQueue(int k) {
        arr = new int[k];
        this -> size = k ;
        front = -1 ;
        rear = -1 ;
    }
    
    bool enQueue(int value) {
        // just write --> front == (rear + 1) % size 
        if(front == (rear + 1) % size ){
            cout << "OverFlow" << endl ;
            return false ;
        }
        else if(front == -1){
            front++;
            rear++;
            arr[rear] = value ;
        }
        else {
            rear = (rear + 1) % size ;
            arr[rear] = value ; 
        }
        return true ;
    }
    
    bool deQueue() {
        if(front == -1){
            cout << "UnderFlow" << endl ;
            return false ;
        }
        else if(front == rear){
            // only one element in queue 
            arr[front] = -1 ;
            front = -1 ;
            rear = -1;
        }
        else {
            arr[front] = -1 ;
            front = (front + 1 ) % size ;
        }
        return true ;
    }
    
    int Front() {
        if(front == -1){
            return -1 ;
        }
        return arr[front];
    }
    
    int Rear() {
        if(front == -1){
            return -1 ;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1 ;
    }
    
    bool isFull() {
        return front == (rear + 1) % size ;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */