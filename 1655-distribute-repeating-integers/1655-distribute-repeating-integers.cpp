class Solution {
public:
    bool canDistributeHelper(vector<int>& freqCount , vector<int>&quantity , int ithCustomer){
        if(ithCustomer == quantity.size()){
            return true ;
        }

        for(int i = 0 ; i < freqCount.size() ; i++){
            if(freqCount[i] >= quantity[ithCustomer]){

                // Chose the frequency for ith customer
                freqCount[i] -= quantity[ithCustomer];

                // Explore for all customer and if ithCustomer == quantity.size() 
                // means all the customers are satisfied then return TRUE
                if(canDistributeHelper(freqCount , quantity , ithCustomer+1)){
                    return true ;
                }
                

                // Backtrack like if any customer is not satisfied then take back integers from him
                // and put it back in freqCount and check if we can allocate with next freqCount
                freqCount[i] += quantity[ithCustomer];

            }
        }

        return false ;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> countMap ;
        for(int i = 0 ; i < nums.size() ; i++){
            countMap[nums[i]]++;
        }
        vector<int> freqCount ;
        for(auto it : countMap){
            freqCount.push_back(it.second);
        }
        sort(quantity.rbegin() , quantity.rend());
        // sort(quantity.begin(), quantity.end() , greater<int>());

        return canDistributeHelper(freqCount , quantity , 0);

    }
};