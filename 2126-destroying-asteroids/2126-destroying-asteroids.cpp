class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin() , asteroids.end());

        for(auto it: asteroids){
            if(it > mass) return false ;
            if(mass > INT_MAX - it) continue;
            mass += it;
        }

        return true ;
    }
};