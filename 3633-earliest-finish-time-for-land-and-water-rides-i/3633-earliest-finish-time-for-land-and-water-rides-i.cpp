class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        // CASE 1:
        // Start with a land ride, choosing the one that finishes earliest.
        int firstFinishLandRide = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            firstFinishLandRide = min(
                firstFinishLandRide,
                landStartTime[i] + landDuration[i]
            );
        }

        int landToWaterTravel = INT_MAX;

        for (int i = 0; i < waterStartTime.size(); i++) {
            landToWaterTravel = min(
                landToWaterTravel,
                max(firstFinishLandRide, waterStartTime[i]) +
                    waterDuration[i]
            );
        }

        // CASE 2:
        // Start with a water ride, choosing the one that finishes earliest.
        int firstFinishWaterRide = INT_MAX;

        for (int i = 0; i < waterStartTime.size(); i++) {
            firstFinishWaterRide = min(
                firstFinishWaterRide,
                waterStartTime[i] + waterDuration[i]
            );
        }

        int waterToLandTravel = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            waterToLandTravel = min(
                waterToLandTravel,
                max(firstFinishWaterRide, landStartTime[i]) +
                    landDuration[i]
            );
        }

        // Return the minimum finishing time among both possibilities.
        return min(landToWaterTravel, waterToLandTravel);
    }
};