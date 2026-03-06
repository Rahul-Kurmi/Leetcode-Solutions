class MinStack {
public:
    vector<pair<int,int>> minSt ;

    MinStack() {}
    
    void push(int val) {
        if(minSt.size() == 0 ){
            // pair<int, int> p =  {val , val};
            // minSt.push_back(p);
            minSt.push_back({val , val});
        }
        else{
            int lastMinVal = minSt.back().second ;
            lastMinVal = min(val , lastMinVal);
            minSt.push_back({val , lastMinVal});
        }
    }
    
    void pop() {
        minSt.pop_back();
    }
    
    int top() {
        return minSt.back().first ;
    }
    
    int getMin() {
        return minSt.back().second ;
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