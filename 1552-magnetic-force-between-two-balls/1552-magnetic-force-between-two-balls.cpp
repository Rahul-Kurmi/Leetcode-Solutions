class Solution {
public:
    int distributeBalls(vector<int>& position , int dist){
        int ballCount = 1 ;
        int i = 0 ;
        int j = i + 1 ;
        while(j < position.size()){
            if(position[j] - position[i] >= dist){
                ballCount++;
                i = j ;
                j = j + 1;
            }else{
                j++;
            }
        }
        return ballCount ;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin() , position.end());
        int start = 0 ;
        int end = position[position.size() - 1] - position[0];
        int ans = 0 ;
        while(start <= end){
            int mid = start + (end - start) / 2 ;
            int totalBall = distributeBalls(position , mid);
            if(totalBall >= m) {
                ans = mid ;
                start = mid + 1 ;
            }else{
                end = mid - 1;
            }
        }
        return ans ;
    }
};