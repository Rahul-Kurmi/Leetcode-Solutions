class MyQueue {
public:
    stack<int> s1 ;
    stack<int> s2 ;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int popElement = -1 ;
        if(!s2.empty()){
            popElement = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            popElement = s2.top();
        }
        s2.pop(); // pop both when s2 empty and non empty 
        return popElement ;
    }
    
    int peek() {
        int frontElement = -1 ;
        if(!s2.empty()){
            frontElement = s2.top() ;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            frontElement = s2.top();
        }
        return frontElement;
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */