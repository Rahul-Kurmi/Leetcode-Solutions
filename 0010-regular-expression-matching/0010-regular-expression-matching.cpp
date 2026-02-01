class Solution {
public:
    bool matchingFunction(string s , string p){
        if(p.size() == 0){
            return s.size() == 0;
        }

        bool first_char_match = (s.size() > 0 && (s[0] == p[0] || p[0] == '.'));

        if(p[1] == '*'){
            bool notTake = matchingFunction(s , p.substr(2));
            bool take = first_char_match && matchingFunction(s.substr(1) , p);

            return notTake || take;
        }

        return first_char_match && matchingFunction(s.substr(1) , p.substr(1));

    }

    bool isMatch(string s, string p) {
        return matchingFunction(s, p);
    }
};