class Trie{
    public :
    char data ;
    Trie* children[26];
    bool isTerminal ;
    Trie(char ch){
        this -> data = ch ;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = nullptr ;
        }
        this -> isTerminal = false ;
    }
};

class WordDictionary {
public:
    Trie* root = new Trie('-');
    WordDictionary() {}
    
    void addWordHelper(Trie* root , string word){
        if(word.length() == 0 ){
            root -> isTerminal = true ;
            return ;
        }

        char ch = word[0];
        int index = ch - 'a';
        Trie* child ;
        if(root -> children[index] != nullptr){
            child = root-> children[index];
        }else{
            child = new Trie(ch);
            root -> children[index] = child;
        }
        addWordHelper(child, word.substr(1));
    }

    void addWord(string word) {
        addWordHelper(root, word);
    }

    bool searchHelper(Trie* root , string word){
        if(word.size() == 0){
            return root -> isTerminal;
        }

        char ch = word[0];
        if(ch == '.'){
            for(int i = 0 ; i < 26 ; i++){
                if(root -> children[i] != nullptr ){
                    if(searchHelper(root -> children[i] , word.substr(1))){
                        return true ;
                    }
                }
            }
        }else{
            int index = ch - 'a';
            if(root -> children[index] != nullptr){
                return searchHelper(root -> children[index] , word.substr(1));
            }
        }
        return false ;
    }
    
    bool search(string word) {
        return searchHelper(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */