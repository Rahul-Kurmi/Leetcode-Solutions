class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int > mp ;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            int check = it.second ;
            for(auto find : mp){
                if(find == it ){
                    continue ;
                }
                if(check == find.second){
                    return false ;
                }
            }
        }

        return true ;
    }
};