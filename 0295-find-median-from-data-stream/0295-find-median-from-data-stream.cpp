class MedianFinder {
public:
    priority_queue<int> left_max_heap ;
    priority_queue<int, vector<int> , greater<int>> right_min_heap;

    MedianFinder() {}
    
    void addNum(int num) {
        // Inserting element in heap 
        if(left_max_heap.empty() || num < left_max_heap.top()){
            left_max_heap.push(num);
        }else{
            right_min_heap.push(num);
        }

        // now balancing or makinf left one just one bigger
        // always maintain left_max_heap size one greater than right_min_heap size
        // or make sure both have same size 

        // we only want left size to be just 1 element greater but if it increses by 1 
        // then shift from left to right
        if((int)left_max_heap.size() - (int)right_min_heap.size() > 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } 
        // means odd size always make sure left hase +1 element
        else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        // EVEN 
        if(left_max_heap.size() == right_min_heap.size()){
            return (left_max_heap.top() + right_min_heap.top()) / 2.0 ;
        }

        // ODD
        return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */