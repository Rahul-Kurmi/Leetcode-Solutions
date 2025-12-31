bool cmp(string a , string b){
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> store ;
        for(auto it : nums){
            store.push_back(to_string(it));
        }

        sort(store.begin() , store.end() , cmp);

        if(store[0] == "0") return "0";

        string ans = "";
        for(auto i = store.begin() ; i != store.end() ; i++){
            ans = ans + *i ;
        }

        return ans ;
    }
};