class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int , int> mp;
        for(auto& num : nums){
            mp[num]++;
        }

        // create bucket of size n+1 
        vector<vector<int>> bucket(n+1);

        for(auto& it: mp){
            int index = it.second; // freq 
            int value = it.first ; // element

            bucket[index].push_back(value);
        }


        vector<int> ans ;
        for(int i = bucket.size() - 1; i>= 0 ; i--){
            if(!bucket[i].empty()){
                for(auto it : bucket[i]){
                    ans.push_back(it);
                    k--;
                    if(k == 0) break ;
                }
            }
            if(k == 0) break ;
        }

        return ans ;
    }
};