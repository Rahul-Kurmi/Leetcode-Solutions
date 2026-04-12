class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq ;

        for(auto it : piles) pq.push(it);

        while(k--){
            int topEle = pq.top();
            pq.pop();
            pq.push((topEle / 2) + (topEle % 2));
        }

        int sum = 0 ;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};