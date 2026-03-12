class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);

        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){

                if(cars[i][1] <= cars[j][1]) continue;

                double relDist = cars[j][0] - cars[i][0];
                double relSpeed = cars[i][1] - cars[j][1];
                double time = relDist / relSpeed;

                if(ans[j] == -1 || time <= ans[j]){
                    ans[i] = time;
                    break;
                }
                if(time > ans[j]) continue ;
            }
        }

        return ans;
    }
};