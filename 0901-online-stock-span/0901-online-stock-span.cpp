class StockSpanner {
public:
    vector<int> arr;

    StockSpanner() {
    }
    
    int next(int price) {
        if(arr.size() == 0) {
            arr.push_back(price);
            return 1;
        } 
        else {
            int i = arr.size() - 1;
            int ans = 0;

            for(i; i >= 0; i--){
                if(arr[i] <= price){
                    ans++;
                }
                else{
                    break;
                }
            }

            arr.push_back(price);
            return ans + 1;
        }
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */