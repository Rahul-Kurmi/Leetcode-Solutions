class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> mp;

        for (int num : nums)
            mp[num]++;

        int ans = 1;

        for (auto it : mp) {
            long long num = it.first;
            int count = 0;

            while(mp.find(num) != mp.end() && mp[num]){
                if(num == 1) count += mp[1];
                else if(mp[num] >= 2) count += 2;
                else if(mp[num] == 1) {
                    count += 1;
                    break;  
                }

                mp[num] = 0; // reset that num which is used    
                if(num > 1e6) break ;
                num = num * num;
            }

            // we did count - (count % 2 == 0) because we want the highest degree value only once 
            ans = max(ans , count - (count % 2 == 0)); 
        }

        return ans;
    }
};