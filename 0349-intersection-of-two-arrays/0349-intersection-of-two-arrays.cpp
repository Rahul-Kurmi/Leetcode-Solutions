class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        int i = 0 , j = 0 ;
        int m = a.size();
        int n = b.size();
        vector<int> ans ;

        while(i < m && j < n){
            if(a[i] < b[j]){
                i++;
            }
            else if(a[i] > b[j]){
                j++;
            }
            else{
                if(ans.empty() || ans.back() != a[i]){
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            }
        }
        return ans ;
    }
};