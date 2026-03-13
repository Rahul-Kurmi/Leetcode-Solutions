int popStack(stack<int>& st){
    if(st.empty()) return -1;
    if(st.size() == 1) {
        int x = st.top() ;
        st.pop() ;
        return x ;
    }
    int temp = st.top() ;
    st.pop() ;
    int ans = popStack(st);
    st.push(temp);
    return ans ; 
}


int peekStack(stack<int>& st){
    if(st.empty()) return -1;
    if(st.size() == 1) {
        int x = st.top() ;
        return x ;
    }
    int temp = st.top() ;
    st.pop() ;
    int ans = peekStack(st);
    st.push(temp);
    return ans ;
}
class MyQueue {
public:
    stack<int> st ;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        return ;
    }
    
    int pop() {
        if(st.empty()) return -1 ;
        return popStack(st);
    }
    
    int peek() {
        return peekStack(st);
    }
    
    bool empty() {
        return st.empty();
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