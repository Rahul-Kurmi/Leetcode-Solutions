class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<double> result ;
        
        multiset<int> left ;
        multiset<int> right ;

        int i = 0 ;
        int j = 0 ;

        while(j < n){
            if(left.size() <= right.size()){
                left.insert(nums[j]);
            }
            else{
                right.insert(nums[j]);
            }

            // balancing
            if(!left.empty() && !right.empty()){
                int leftMax = *left.rbegin();
                int rightMin = *right.begin();

                if(leftMax > rightMin){
                    left.erase(left.find(leftMax)); // giving it iterator
                    left.insert(rightMin);

                    right.erase(right.find(rightMin));
                    right.insert(leftMax);
                }
            }

            // k size subarray 
            if(j - i + 1 == k){
                double median;
                if(left.size() > right.size()){
                    median = (double)(*left.rbegin()); 
                }
                else{
                    median = ((double)(*left.rbegin()) + (*right.begin())) / 2.0;
                }

                // erase the ith index ele from set --> as we increase i 
                if(left.find(nums[i]) != left.end()){
                    auto it = left.find(nums[i]);
                    left.erase(it);
                }
                else{
                    auto it = right.find(nums[i]);
                    right.erase(it);
                }

                i++; // increment i

                // insert median in result 
                result.push_back(median);
            }

            j++; // increment j
        }

        return result ;
    }
};