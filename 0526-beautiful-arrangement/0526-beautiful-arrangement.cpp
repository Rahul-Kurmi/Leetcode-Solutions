class Solution {
public:
    void findingArrangements(vector<int>& arr, int&n , int&ansCount , int currNum){
        if(currNum == n+1){
            ++ansCount;
            return ;
        }

        // iterate from 1 index
        for(int i = 1 ; i <= n ; i++){
            if (arr[i] == 0 && ( (currNum % i == 0) || (i % currNum == 0) )){
                arr[i] = currNum ;
                findingArrangements(arr, n , ansCount , currNum + 1);
                arr[i] = 0 ; // BackTracking
            }
        }
    }

    int countArrangement(int n) {
        // Here we will iterate form 1 index only in the recursion function thus taking size of array n + 1 
        vector<int> arr(n+1); // Initially every element is initailized by 0
        int ans = 0 ;
        findingArrangements(arr, n , ans , 1);
        return ans;
    }
};