class TrieNode{
    public:
        int val ;
        TrieNode* children[26] ;
        pair<int, int> storeData; // index, size

        TrieNode(int val , int index , int size){
            this -> val = val;
            for(int i = 0 ; i < 26 ; i++){
                children[i] = nullptr ;
            }

            storeData.first = index;
            storeData.second = size;
        }

        ~TrieNode() { // Destructor
            for (auto &it : children) {
                delete it;
            }
        }
};

class Solution {
public:

    void insertData(TrieNode* root , string &str , int strIndex, int i){
        if(i == str.size()) return ;

        int index = str[i] - 'a';
        if(root -> children[index] != nullptr){
            if(root -> children[index] -> storeData.second > str.size()){
                root -> children[index] -> storeData.second = str.size();
                root -> children[index] -> storeData.first = strIndex;
            }
            insertData(root -> children[index], str, strIndex, i+1);
        }
        else{
            TrieNode* newNode = new TrieNode(str[i] , strIndex , str.size());
            root -> children[index] = newNode ;
            insertData(newNode , str, strIndex, i+1);
        }
    }

    int findSuffix(TrieNode* root, string &str, int i){
        if(i == str.size()) {
            return root -> storeData.first;
        }

        int index = str[i] - 'a';
        if(root -> children[index] == nullptr){
            return root -> storeData.first;
        }
        else{
            return findSuffix(root -> children[index] , str , i+1);
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode('-' , INT_MAX , INT_MAX);
        int m = wordsContainer.size();
        int n = wordsQuery.size();
        vector<int> ans(n);

        for(int i = 0 ; i < m ; i++){
            string str = wordsContainer[i];
            if(root -> storeData.second > str.size()){
                root -> storeData.first = i ;
                root -> storeData.second = str.size();
            }

            reverse(str.begin() , str.end());

            insertData(root , str , i , 0);
        }


        for(int i = 0 ; i < n ; i++){
            string str = wordsQuery[i];
            reverse(str.begin() , str.end());

            int findCommonSuffix = findSuffix(root , str, 0);

            ans[i] = findCommonSuffix;
        }

        delete root;

        return ans ;
    }
};