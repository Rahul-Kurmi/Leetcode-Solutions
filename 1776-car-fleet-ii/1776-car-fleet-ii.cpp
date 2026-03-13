class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size() ;
        vector<double> ans(n  , -1) ;
        stack<int> st ;
        for(int i = n - 1; i >= 0 ; i--){
            // pop all the cars from top whose speed is more than current car
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            // Now we got car with slow speed so check if time of stTop >= curr Car
            while(!st.empty()){
                double dist = cars[st.top()][0] - cars[i][0];
                double speed = cars[i][1] - cars[st.top()][1] ;
                double time = dist / speed ;
                if(ans[st.top()] == -1 || time <= ans[st.top()]){
                    // meean this collision happens 
                    ans[i] = time ;
                    break ; // we don't want next itration
                } 

                // we want next iteration as the time of ahead is less thus it collided first 
                // so check for the next car ahead of this one
                st.pop();
            }

            // push curr car index in stack for further cars behind
            st.push(i);
        }

        return ans ;
    }
};