class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size() ;
        vector<double> ans(n , -1) ;
        stack<int> st ;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty()){
                // skip for those when currentCar cannot catch the topCar ie Car Ahead
                int currSpeed = cars[i][1] ;
                int stTopSpeed = cars[st.top()][1];
                if(currSpeed <= stTopSpeed){
                    st.pop();
                    continue ; // As we have to check for next top with less speed than curr
                }

                // Now calculate time to reach the stTop car as skipped all faster cars now we are faster than the ahead one
                double dist = cars[st.top()][0] - cars[i][0];
                double speed = cars[i][1] - cars[st.top()][1];
                double time = dist / speed ;

                // Now if ahead car time = -1 ie it never collides with ahead car 
                // or it's time is more than equal to current one thus this car will collide first 
                if(ans[st.top()] == -1 || time <= ans[st.top()]){
                    ans[i] = time ;
                    break ; // don't go to nest iteration as found ans 
                }

                // pop as currentTime is more than achead time ie. ahead one collided first
                // Now we have to check with the one it's collidex
                st.pop();
            }

            // After this while loop we have found our ans --> push the current index for behind cars
            st.push(i);
        }

        return ans ;
    }
};