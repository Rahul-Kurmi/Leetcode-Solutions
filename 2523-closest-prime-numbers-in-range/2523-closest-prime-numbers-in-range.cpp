class Solution {
public:
    vector<bool> Seive(int num){
        vector<bool>isPrime(num + 1 , true);
        isPrime[0] = false ;
        isPrime[1] = false ;

        for(int i = 2 ; i <= num ; i++){    
            if(isPrime[i]){
                int j = i * i ;
                while(j <= num){
                    isPrime[j] = false ;
                    j = j + i ;
                }
            }
        }
        return isPrime ;
    }

    vector<bool> segmentedSeive(int left , int right){
        vector<bool>seive = Seive(sqrt(right));
        vector<int>basePrime ;
        for(int i = 2 ; i < seive.size() ; i++){
            if(seive[i]){
                basePrime.push_back(i);
            }
        }

        vector<bool> segSeive(right - left  + 1 , true);
        if(left == 1 || left == 0){
            segSeive[0] = false ;
        }

        for(auto prime : basePrime){
            int first_mul = (left / prime) * prime ;
            if(first_mul < left){
                first_mul = first_mul + prime ;
            }

            int j = max(first_mul , prime*prime);
            while(j <= right){
                segSeive[j - left] = false ;
                j = j + prime ;
            }
        }
        return segSeive ;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> inBetweenPrimes = segmentedSeive(left  , right);
        vector<int> prime;
        for(int i = 0 ; i < inBetweenPrimes.size(); i++){
            if(inBetweenPrimes[i]){
                prime.push_back(left + i);
            }
        }
        if(prime.size() < 2){
            return {-1 ,-1};
        }
        int min_dist = INT_MAX ;
        vector<int> ans(2);
        for(int i = 1 ; i < prime.size() ; i++){
            int dist = prime[i] - prime[i-1];
            if(dist < min_dist){
                min_dist = dist;
               ans[0] = prime[i-1];
               ans[1] = prime[i];
            }
        }
        return ans ;
    }
};