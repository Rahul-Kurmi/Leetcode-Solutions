class StockSpanner {
public:
    stack<pair<int , int>> st ;
    int index = -1 ; // initial index 
    
    StockSpanner() {
        // Make sure when StockSpanner is reiitialized the inidex becomes -1
        // and stack is empty
        index = -1 ;
        while(!st.empty()){
            st.pop();
        }
    }
    
    int next(int price) {
        index++;

        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int ans;

        if(st.empty())
            ans = index + 1;
        else
            ans = index - st.top().second;

        st.push({price, index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */