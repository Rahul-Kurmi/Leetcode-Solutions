class Solution {
public:
    unordered_map<string, int > mp ; // word -> level --> stores level of each word
    unordered_set<string> st ; // fetch word in O(1) amotized
    vector<vector<string>> ans ; // store ans here

    void dfs(string currWord, string beginWord,  vector<string>& store){
        if(currWord == beginWord){
            reverse(store.begin(), store.end());
            ans.push_back(store);
            reverse(store.begin(), store.end()); // so when we do pop in previous call stack it's done properly 
            return;
        }

        for(int i = 0 ; i < currWord.size() ; i++){
            string dummyWord = currWord ;
            for(int j = 0 ; j < 26 ; j++){
                char ch = j + 'a';
                dummyWord[i] = ch ;
                if(mp.find(dummyWord) != mp.end()){
                    int currWordLevel = mp[currWord];
                    int dummyWordLevel = mp[dummyWord];

                    if(currWordLevel == 1 + dummyWordLevel){
                        store.push_back(dummyWord);
                        dfs(dummyWord, beginWord, store);
                        store.pop_back(); // for next iteration at same level we need to pop
                    }
                }
            }
        }
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(auto& word : wordList){
            st.insert(word);
        }

        int level = 0 ;
        queue<string> q ;
        q.push(beginWord);

        // insert begiinWord in map 
        mp.insert({beginWord, 0});

        while(!q.empty()){
            int qSize = q.size();
            bool isEndWord = false ;

            for(int size = 0 ; size < qSize ; size++){
                string currWord = q.front();
                q.pop();

                for(int i = 0 ; i < currWord.size() ; i++){
                    string dummyWord = currWord ;
                    for(int j = 0 ; j < 26 ; j++){
                        char ch = j + 'a';
                        dummyWord[i] = ch ;
                        if(st.count(dummyWord) > 0){
                            mp.insert({dummyWord, level+1});
                            st.erase(dummyWord);
                            q.push(dummyWord);
                            if(dummyWord == endWord) isEndWord = true ;
                        }
                    }
                }
            }
            level++;
            if(isEndWord) break ;
        }

        vector<string> store ;
        store.push_back(endWord);
        dfs(endWord , beginWord,  store);

        return ans;
    }
};