class TrieNode{
    public :
        int idx; // store index of the loweest suffix Match
        TrieNode* children[26];
        TrieNode(int idx){
            this -> idx = idx ;
            for(int i = 0 ; i < 26 ; i++){
                children[i] = nullptr;
            }
        }

        ~TrieNode(){
            for(auto &it: children){
                delete it;
            }
        }
};

class Solution {
public:

    void insertInTrie(TrieNode* root, int strIndex ,  vector<string>& wordsContainer){
        string word = wordsContainer[strIndex];
        int n = wordsContainer[strIndex].size();

        for(int i = n - 1 ; i >= 0 ; i--){
            int index = word[i] - 'a';

            if(root -> children[index] == nullptr){
                root -> children[index] = new TrieNode(strIndex);
            }

            root = root -> children[index]; // update root 

            if(wordsContainer[root -> idx].size() > wordsContainer[strIndex].size()){
                root -> idx = strIndex;
            }
        }
    }

    int searchInTrie(TrieNode* root, int strIndex ,  vector<string>& wordsQuery){
        string word = wordsQuery[strIndex];
        int n = wordsQuery[strIndex].size();

        int resultIdx = root -> idx ;
        for(int i = n-1 ; i >= 0; i--){
            int index = word[i] - 'a';
            if(root -> children[index] == nullptr){
                return resultIdx;
            }

            root = root -> children[index];

            resultIdx = root -> idx ;
        }

        return resultIdx ;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();
        TrieNode* root = new TrieNode(0) ; // store index of first word
        for(int i = 0 ; i < m ; i++){
            if(wordsContainer[root -> idx].size() > wordsContainer[i].size()){
                root -> idx = i ;
            }

            insertInTrie(root , i , wordsContainer);
        }

        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            ans[i] = searchInTrie(root, i, wordsQuery);
        }

        delete root; // delete Trie

        return ans ;
    }
};