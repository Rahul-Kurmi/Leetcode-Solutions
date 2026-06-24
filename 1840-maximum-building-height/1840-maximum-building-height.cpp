class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // for Left to right pass
        restrictions.push_back({1, 0});

        // for Right to Left pass
        restrictions.push_back({n , n-1});

        // Sort for correction of restriction
        sort(restrictions.begin() , restrictions.end());

        int N = restrictions.size();

        // Doing Left to Right Correction
        for(int i = 1 ; i < N ; i++){
            int distDiff = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i-1][1] + distDiff);
        }

        // Doing Right to Left Correction
        for(int i = N - 2 ; i >= 0 ; i--){
            int distDiff = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i+1][1] + distDiff);
        }

        // Applying logic for tallest building
        int result = 0 ;

        for(int i = 1 ; i < N ; i++){
            int leftPos = restrictions[i-1][0];
            int leftHt = restrictions[i-1][1];

            int currPos = restrictions[i][0];
            int currHt = restrictions[i][1];

            int d = currPos - leftPos;
            int htDiff = abs(leftHt - currHt);

            int peak = max(leftHt , currHt) + (d - htDiff)/2 ;
            
            result = max(result , peak);
        }

        return result ;



    }
};