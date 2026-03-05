class MinStack {
public:
    vector<int> arr ;
    vector<int> minArr ;
    MinStack() {
        
    }
    
    void push(int val) {
        if(arr.size() == 0){
            arr.push_back(val);
            minArr.push_back(val);
        }
        else{
            int lastVal = minArr.back();
            lastVal = min(lastVal , val);
            arr.push_back(val);
            minArr.push_back(lastVal);
        }
    }
    
    void pop() {
        arr.pop_back();
        minArr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return minArr.back();
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