class MyQueue {
public:
    stack<int> s1 ;
    stack<int> s2 ;
    MyQueue() {
        
    }
    
    void push(int x) {
        // Step 1 : Copy all elements from s1 to s2 
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2 : Push x in s1 as now it will be bottom of st or rear of queue 
        s1.push(x);

        // step 3: Copy all elements from s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int element = s1.top();
        s1.pop();
        return element ;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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