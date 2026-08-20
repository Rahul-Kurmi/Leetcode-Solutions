class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // push all the words in u_set to fetch in O(1)
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<pair<string, int>> q; // word -> it's level
        q.push({beginWord, 1});

        // erase the beginWord from set id it's present
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second ; 
            q.pop();

            if(word == endWord) return steps ; // found our word 

            for(int i = 0 ; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch ;
                    if(st.find(word) != st.end()){ // it exist in set 
                        st.erase(word); // remove from set
                        q.push({word, steps + 1});
                    }
                }

                word[i] = original ; // replace character changed with original one
            }
        }  

        return 0;
    }
};