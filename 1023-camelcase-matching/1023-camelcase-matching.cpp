class TrieNode{
    public:
        char data ;
        TrieNode* children[256];
        bool isTerminal;

        TrieNode(char ch){
            this -> data = ch;
            for(int i = 0 ; i < 256 ; i++){
                children[i] = nullptr ;
            }
            this -> isTerminal = false;
        }
};

class Solution {
public:
    void insertUtil(TrieNode* root, string word , int i){
        if(i == word.length()){
            root -> isTerminal = true ;
            return ;
        }

        int index = word[i];
        if(!root -> children[index]){
            root -> children[index] = new TrieNode(word[i]);
        }

        insertUtil(root -> children[index] , word , i+1);
    }


    bool isCamelMatch(TrieNode* root , string word, int i){
        if(i == word.size()){
            return root->isTerminal; // ✅ ensure full match
        }

        int index = word[i];
        if(root -> children[index]){
            return isCamelMatch(root -> children[index] , word, i+1);
        }
        else if(islower(word[i])){
            return isCamelMatch(root , word, i+1);
        }
        return false;
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        TrieNode* root = new TrieNode('-');
        insertUtil(root , pattern , 0);
        vector<bool> ans ;
        for(auto word : queries){
            ans.push_back(isCamelMatch(root , word, 0));
        }
        return ans ;
    }
};