class Solution {
public:
    bool countingHours(vector<int>& arr , int k , int h){
        int hours = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            hours += arr[i]/k ;
            if(arr[i]%k != 0) hours++;
            if(hours > h) return false ; 
        }
        return true ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 ;
        int end = *max_element(piles.begin() , piles.end());
        int ans = 0 ;
        while(start <= end){
            int mid = start + (end - start) / 2 ;
            if(countingHours(piles , mid , h)){
                ans = mid ;
                end = mid - 1;
            }else{
                start = mid + 1 ;
            }
        }
        return ans ;
    }
};