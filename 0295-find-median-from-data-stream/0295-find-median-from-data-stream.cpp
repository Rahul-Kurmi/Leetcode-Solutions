class MedianFinder {
private :
    priority_queue<int> maxHeap ;
    priority_queue<int, vector<int> , greater<int>> minHeap;
    double median = 0.0 ;

    void insertAndGetMedian(int element){
        if(maxHeap.size() == minHeap.size()){
            if(element > median){
                minHeap.push(element);
                median = minHeap.top();
            }
            else{
                maxHeap.push(element);
                median = maxHeap.top();
            }
        }
        else if(maxHeap.size() > minHeap.size()){
            if(element > median){
                minHeap.push(element);
                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }
            else{
                int maxTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxTop);

                maxHeap.push(element);

                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }
        }
        else if(minHeap.size() > maxHeap.size()){
            if(element > median){
                int minTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minTop);

                minHeap.push(element);

                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }
            else{
                maxHeap.push(element);
                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }
        }
    }

    


public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        insertAndGetMedian(num);
    }
    
    double findMedian() {
        return this->median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */