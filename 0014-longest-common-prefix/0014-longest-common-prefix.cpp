class TrieNode{
    public :
        char data ;
        TrieNode* children[26];
        bool isTreminal ;
        int childCount ;
        TrieNode(int _ch){
            this -> data = _ch ;
            for(int i = 0 ; i < 26 ; i++){
                children[i] = nullptr ;
            }
            this -> childCount = 0;
            this -> isTreminal = false ;
        }
};

class Solution {
public:
    void insertWord(TrieNode* root , string word){
        if(word.length() == 0){
            root -> isTreminal = true ;
            return ;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child ;
        if(root -> children[index] != nullptr){
            child = root -> children[index]; 
        }
        else{
            child = new TrieNode(ch);
            root -> children[index] = child ;
            root -> childCount++;
        }

        insertWord(child , word.substr(1));
    }

    void findLCP(TrieNode* root, string& ans , string first){
        if(root -> isTreminal) return ;

        for(int i = 0 ; i < first.size() ; i++){
            char ch = first[i];
            if(root -> childCount == 1){
                ans += ch;
                int index = ch - 'a';
                root = root -> children[index];
            }
            else{
                break;
            }
            
            if(root -> isTreminal){
                break;
            }
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode * root = new TrieNode('-');
        
        // Insert String 
        for(int i = 0 ; i < strs.size() ; i++){
            insertWord(root , strs[i]);
        }
        
        string ans = "";
        
        string first = strs[0] ;
        findLCP(root , ans , first) ;
        return ans ;
    }
};