class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        sort(arr.begin() , arr.end());
        if(arr.size() == 1) return 0 ;
        int i = 0 ;
        int j = i + 1;
        int ans = 0;
        while(j < arr.size()){
            if(i == j){ 
                j++; 
                continue;
            }
            if(arr[j] - arr[i] == k){
                ans++;
                i++;
                j++;

                while(j < arr.size() && arr[j] == arr[j-1]) j++;
            }
            else if(arr[j] - arr[i] < k) j++;
            else i++;
        }
        return ans ;
    }
};