class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        
        set<vector<int>> st;

        // store unique initial points
        for (auto &p : points) {
            st.insert(p);
        }

        // target already exists
        if (st.count(target)) {
            return 0;
        }

        int generations = 0;

        while (true) {

            int n = points.size();

            vector<vector<int>> newPoints;

            // only process OLD points of this generation
            for (int i = 0; i < n; i++) {

                for (int j = i + 1; j < n; j++) {

                    int x = (points[i][0] + points[j][0]) / 2;
                    int y = (points[i][1] + points[j][1]) / 2;
                    int z = (points[i][2] + points[j][2]) / 2;

                    vector<int> mid = {x, y, z};

                    // add only new points
                    if (!st.count(mid)) {

                        st.insert(mid);
                        newPoints.push_back(mid);

                        // target found
                        if (mid == target) {
                            return generations + 1;
                        }
                    }
                }
            }

            // no new points generated
            if (newPoints.empty()) {
                return -1;
            }

            // add after finishing this generation
            for (auto &p : newPoints) {
                points.push_back(p);
            }

            generations++;
        }

        return -1;
    }
};