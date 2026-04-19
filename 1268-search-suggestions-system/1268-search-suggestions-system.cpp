class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char _ch){
        data = _ch;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Solution {
public:
    void insertWord(TrieNode* root , string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child;
        if(root->children[index] != nullptr){
            child = root->children[index];
        }
        else{
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertWord(child , word.substr(1));
    }

    void searchAllSuggestions(TrieNode* root, vector<string>& suggestions, string& store){
        if(!root) return;

        if(root->isTerminal){
            suggestions.push_back(store);
            if(suggestions.size() == 3) return;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(root->children[i] != nullptr){
                store.push_back('a' + i);
                searchAllSuggestions(root->children[i], suggestions, store); // ✅ FIX
                store.pop_back();

                if(suggestions.size() == 3) return;
            }
        }
    }

    void getSuggestion(TrieNode* root , string input, vector<string>& suggestions , string& store){

        if(input.size() == 0){
            searchAllSuggestions(root, suggestions, store);
            return;
        }

        char ch = input[0];
        int index = ch - 'a';

        if(root->children[index] == nullptr) return;  // ✅ FIX

        store.push_back(ch);
        getSuggestion(root->children[index], input.substr(1), suggestions, store);
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode('-');

        for(auto it : products){
            insertWord(root, it);
        }

        vector<vector<string>> ans;
        string searchInput = "";

        for(int i = 0 ; i < searchWord.size() ; i++){
            searchInput += searchWord[i];

            vector<string> suggestions;
            string store = "";

            getSuggestion(root, searchInput , suggestions , store);

            ans.push_back(suggestions);
        }

        return ans;
    }
};