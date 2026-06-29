class Solution {
public:
    int solve(vector<int>& satisfaction, int i , int time, vector<vector<int>>& dp){
        if(i == satisfaction.size()) return 0 ;

        if(dp[i][time] != -1) return dp[i][time];

        int includeTimeCoefficient = time * satisfaction[i] + solve(satisfaction , i+1, time + 1, dp);

        int excludeTimeCoefficient = solve(satisfaction , i+1, time, dp);

        return dp[i][time] =  max(includeTimeCoefficient, excludeTimeCoefficient);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for(int i = n-1 ; i >= 0 ; i--){
            for(int time = n ; time >= 1 ; time--){
                int includeTimeCoefficient = time * satisfaction[i] + dp[i+1][time+1];

                int excludeTimeCoefficient = dp[i+1][time];

                dp[i][time] =  max(includeTimeCoefficient, excludeTimeCoefficient);
            }
        }

        return dp[0][1];
    }
};