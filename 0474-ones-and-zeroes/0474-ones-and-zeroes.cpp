class Solution {
public:
    void countZerosOnesHelper(vector<pair<int,int>>&countZerosOnes, vector<string>&strs){
        for(auto &str : strs){
            int zeroCount = 0 ;
            int oneCount = 0;
            for(auto &ch : str){
                if(ch == '0') zeroCount++;
                else oneCount++;
            }
            countZerosOnes.push_back({zeroCount, oneCount});
        }
    }

    int findMaxFormHelper(vector<pair<int, int>>& countZerosOnes, int m , int n, int i, vector<vector<vector<int>>>& dp){
        if(i == countZerosOnes.size()) return 0 ;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zeroCount = countZerosOnes[i].first ;
        int oneCount = countZerosOnes[i].second ;

        int include = 0 ;
        if(zeroCount <= m && oneCount <= n){
            include =  1 + findMaxFormHelper(countZerosOnes , m-zeroCount, n-oneCount, i+1, dp);
        }

        int exclude = findMaxFormHelper(countZerosOnes , m , n, i+1, dp);

        return dp[i][m][n] =  max(include, exclude);         
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> countZerosOnes ;
        // fill 0's and 1's 
        countZerosOnesHelper(countZerosOnes, strs);

        int size = strs.size();
        // TABULATION  DP --> changing parameter --> i , m , n --> 3D Dp
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m+1, vector<int>(n+1 , 0)));

        // BASE CASE --> when i == n return 0, no need to write as all initialized with 0

        for(int i = size-1 ; i >= 0 ; i--){
            for(int t_zeros = 0 ; t_zeros <= m ; t_zeros++){
                for(int t_ones = 0 ; t_ones <= n; t_ones++){
                    int zeroCount = countZerosOnes[i].first ;
                    int oneCount = countZerosOnes[i].second ;

                    int include = 0 ;
                    if(zeroCount <= t_zeros && oneCount <= t_ones){ 
                        include =  1 + dp[i+1][t_zeros-zeroCount][t_ones-oneCount] ;
                    }

                    int exclude = dp[i+1][t_zeros][t_ones];

                    dp[i][t_zeros][t_ones] =  max(include, exclude);
                }
            }
        }

        return dp[0][m][n];
    }
};