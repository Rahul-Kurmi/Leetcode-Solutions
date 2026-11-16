class Solution {
public:
    int n;
    int k;

    int getSum(string subString){
        int sum = 0;
        for(char ch : subString){
            sum += (ch - '0');
        }
        return sum;
    }

    void solve(string& s){
        string result = "";

        int i = 0;
        while(i < n){
            string subString = "";

            if(i + k < n){
                subString = s.substr(i, k);
                int sum = getSum(subString);
                subString = to_string(sum);
            }
            else{
                subString = s.substr(i);
                int sum = getSum(subString);
                subString = to_string(sum);
            }

            result += subString;
            i = i + k;
        }

        s = result;
    }

    string digitSum(string s, int k) {
        this->k = k;

        while(s.size() > k){
            n = s.size();
            solve(s);
        }

        return s;
    }
};