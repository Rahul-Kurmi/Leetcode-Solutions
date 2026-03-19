class MyStack {
public:
    queue<int> q1 ;
    queue<int> q2 ;
    MyStack() {
        
    }
    
    void push(int x) {
        // Step 1 : Push elemtnt in q2 
        q2.push(x);

        // Step 2 : Push all elements form s1 to s2 
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3 : Push all elements from s2 to s1 ;
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int popElement = q1.front();
        q1.pop();
        return popElement ;
    }
    
    int top() {
        return q1.empty() ? -1 : q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */