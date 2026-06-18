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

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> countZerosOnes;
        countZerosOnesHelper(countZerosOnes, strs);

        int size = strs.size();
        // SPACE OPTIMIZED using 2, 2D array --> size => 2*(m+1)*(n+1)
        vector<vector<int>> next(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));

        for(int i = size - 1; i >= 0; i--) {
            for(int t_zeros = 0; t_zeros <= m; t_zeros++) {
                for(int t_ones = 0; t_ones <= n; t_ones++) {

                    int zeroCount = countZerosOnes[i].first;
                    int oneCount  = countZerosOnes[i].second;

                    int include = 0;
                    if(zeroCount <= t_zeros &&
                    oneCount <= t_ones) {
                        include = 1 +next[t_zeros - zeroCount][t_ones - oneCount];
                    }

                    int exclude = next[t_zeros][t_ones];
                    curr[t_zeros][t_ones] = max(include, exclude);
                }
            }
            next = curr;
        }
        return next[m][n];
    }
};