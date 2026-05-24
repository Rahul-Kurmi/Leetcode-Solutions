class Solution {
public:
    int maxJumpsHelper(vector<int>& arr, int start, int d , vector<int>& dp){

        if(start >= arr.size() || start < 0) return 0 ;

        if(dp[start] != -1) return dp[start];

        int result = 1 ; // visited current index 

        // left possible jumps
        // j >=  max(0 , start - d) as start - d is last possible jump and 0 is bound check
        for(int j = start - 1 ; j >= max(0 , start - d) ; j--){
            if(arr[j] >= arr[start]) break ; // can't jump to higher building
            result = max(result , 1 + maxJumpsHelper(arr , j , d, dp));
        } 

        // right possible jumps 
        // j <= min(arr.size() - 1, start + d) is last possible jump with bound check
        for(int j = start + 1 ; j <= min((int)arr.size() - 1 , start + d) ; j++){
            if(arr[j] >= arr[start]) break ;
            result = max(result , 1 + maxJumpsHelper(arr, j , d, dp));
        }

        return dp[start] =  result ;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n , -1);
        int result = 1 ;
        for(int jumpStart = 0 ; jumpStart < n ; jumpStart++){
            result = max(result , maxJumpsHelper(arr, jumpStart, d, dp));
        }

        return result ;
    }
};