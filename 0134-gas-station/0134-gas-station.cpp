class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficitGas = 0;
        int remainingGas = 0 ;
        int start = 0;
        for(int i = 0 ; i < gas.size() ; i++){
            remainingGas += gas[i] - cost[i];

            if(remainingGas < 0){
                deficitGas += abs(remainingGas) ;
                remainingGas = 0 ;
                start = i + 1 ;
            }
        }

        if(remainingGas >= deficitGas) return start ;
        return -1 ;
    }
};