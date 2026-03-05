class MinStack {
public:
    vector<int> arr;

    MinStack() {}

    void push(int val) {
        arr.push_back(val);
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        int mini = INT_MAX;
        for(int x : arr){
            mini = min(mini, x);
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */