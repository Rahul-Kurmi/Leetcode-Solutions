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
        // DP --> changing parameter --> i , m , n --> 3D Dp
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m+1, vector<int>(n+1 , -1)));

        return findMaxFormHelper(countZerosOnes, m, n , 0, dp);
    }
};