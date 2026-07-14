class Solution {
public:
    int MOD = 1e9 + 7; 

    int gcd(int a , int b){
        if(b == 0) return a;
        return gcd(b , a % b);
    }

    int subsequencePairCount(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> curr(maxVal+1, vector<int>(maxVal+1, -1));
        vector<vector<int>> next(maxVal+1, vector<int>(maxVal+1, -1));

        // TABULATION CODE : SPACE OPTIMIZED
        // BASE CASE

        for(int gcdFirst = 0 ; gcdFirst <= maxVal ; gcdFirst++){
            for(int gcdSecond = 0; gcdSecond <= maxVal ; gcdSecond++){
                bool bothNonEmpty = (gcdFirst != 0 && gcdSecond != 0);
                bool gcdMatch = (gcdFirst == gcdSecond);
                
                next[gcdFirst][gcdSecond] = (bothNonEmpty && gcdMatch) ? 1 : 0;
            }
        }


        for(int i = n-1 ; i >= 0 ; i--){
            for(int gcdFirst = maxVal ; gcdFirst >= 0 ; gcdFirst--){
                for(int gcdSecond = maxVal ; gcdSecond >= 0 ; gcdSecond--){
                    int skip = next[gcdFirst][gcdSecond] ;

                    int take1 = next[gcd(gcdFirst, nums[i])][gcdSecond];

                    int take2 = next[gcdFirst][gcd(gcdSecond, nums[i])];

                    curr[gcdFirst][gcdSecond]  = ((skip + take1)% MOD + take2) % MOD ;
                }
            }

            next = curr ;
        }


        return next[0][0];
    }
};