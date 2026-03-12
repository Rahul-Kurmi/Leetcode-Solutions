class Solution {
    class Car{
        public : 
            int pos ;
            int speed ;
            Car(int _p , int _s) : pos(_p) , speed(_s) {} ;
    };

    static bool cmp(Car c1 , Car c2){
        return c1.pos < c2.pos ;
    }

    

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size() ;
        vector<Car> cars ;
        for(int i = 0 ; i < n ; i++){
            Car c1(position[i] , speed[i]);
            cars.push_back(c1) ;
        }

        sort(cars.begin(), cars.end(), cmp);
        // can also use --> but no need as we're in Solution class itself 
        // sort(cars.begin(), cars.end(), Solution::cmp);

        vector<double> times ;
        for(int i = 0 ; i < n ; i++){
            double time = (target - cars[i].pos)/((float)cars[i].speed);
            times.push_back(time);
        }

        stack<double> st ;
        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                st.push(times[i]);
            }else{
                while(!st.empty() && st.top() <= times[i]){
                    st.pop();
                }
                st.push(times[i]);
            }
        }

        return st.size();
    }
};