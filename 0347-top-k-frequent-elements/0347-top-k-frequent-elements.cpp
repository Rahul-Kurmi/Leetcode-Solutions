class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. get freq count
        unordered_map<int, int> mp;
        for(int &num : nums){
            mp[num]++;
        }

        //2. Define min-Heap;
        priority_queue<P, vector<P> , greater<P>> pq ; // {freq , element}

        //3. push element in min-heap and maintail size of only k
        for(auto &it : mp){
            int value = it.first ;
            int freq = it.second;

            pq.push({freq, value});

            if(pq.size() > k){
                pq.pop();
            }
        }

        //4. result 
        vector<int> result ;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result; 
    }
};