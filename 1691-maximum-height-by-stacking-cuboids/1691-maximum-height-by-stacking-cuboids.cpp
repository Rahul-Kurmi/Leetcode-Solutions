class Solution {
public:

    bool canTake(vector<vector<int>>& cuboids, int i, int prev) {
        if ((cuboids[i][0] >= cuboids[prev][0]) && 
            (cuboids[i][1] >= cuboids[prev][1]) &&
            (cuboids[i][2] >= cuboids[prev][2])) {
            return true;
        }

        return false;
    }

    int LIShelper(vector<vector<int>>& cuboids, int i, int prev) {
        if (i == cuboids.size()) return 0;

        int take = 0;

        if (prev == -1 || canTake(cuboids, i, prev)) {
            take = cuboids[i][2] + LIShelper(cuboids, i + 1, i);
        }

        int skip = LIShelper(cuboids, i + 1, prev);

        return max(take, skip);
    }

    int maxHeight(vector<vector<int>>& cuboids) {

        // Sort dimensions of each cuboid so that:
        // cuboid[0] <= cuboid[1] <= cuboid[2].
        // This allows us to treat the largest dimension as height
        // and the other two as base dimensions.
        // Since cuboids can be rotated, sorting normalizes every cuboid
        // into its best comparable orientation.
        for (auto &it : cuboids) {
            sort(it.begin(), it.end());
        }

        // Sort all cuboids lexicographically by their dimensions.
        // This ensures smaller cuboids come before larger cuboids.
        // After this ordering, the problem becomes similar to LIS:
        // we try to build the longest/maximum-height increasing sequence
        // where each next cuboid must have all dimensions >= previous cuboid.
        sort(cuboids.begin(), cuboids.end());

        // Apply LIS-style recursion:
        // At every index, decide whether to take the current cuboid
        // on top of the previous selected cuboid or skip it.
        return LIShelper(cuboids, 0, -1);
    }
};