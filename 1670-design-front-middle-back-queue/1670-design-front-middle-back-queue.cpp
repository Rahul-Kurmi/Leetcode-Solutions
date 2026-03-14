class FrontMiddleBackQueue {
    vector<int> arr ;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        arr.insert(arr.begin() , val);
    }
    
    void pushMiddle(int val) {
        int index = arr.size() / 2 ;
        arr.insert(arr.begin() + index , val);
    }
    
    void pushBack(int val) {
        arr.push_back(val);
    }
    
    int popFront() {
        if(arr.empty()) return -1;
        int element = arr[0];
        arr.erase(arr.begin());
        return element ;
    }
    
    int popMiddle() {
        if(arr.empty()) return -1;

        int index = (arr.size() - 1) / 2;
        int element = arr[index];
        arr.erase(arr.begin() + index );
        return element ;
    }
    
    int popBack() {
        if(arr.empty()) return -1;
        int element = arr.back();
        arr.pop_back();
        return element ;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */