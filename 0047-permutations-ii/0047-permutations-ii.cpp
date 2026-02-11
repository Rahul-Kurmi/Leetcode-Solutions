class Solution {
public:
    vector<vector<int>> ans ;

    void findingAns(vector<int>& arr, int start ){
        if(start == arr.size()){
            ans.push_back(arr);
            return ;
        }

        set<int> visited ;
        for(int i = start ; i < arr.size() ; i++){
            // check if visited 
            if(visited.find(arr[i]) != visited.end()) continue ;
            visited.insert(arr[i]); 

            swap(arr[i] , arr[start]);
            findingAns(arr, start+1);
            swap(arr[i] , arr[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        findingAns(nums , 0);
        return ans ;
    }
};