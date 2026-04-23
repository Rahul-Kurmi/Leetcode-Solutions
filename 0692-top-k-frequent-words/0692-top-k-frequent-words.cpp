class TrieNode{
    public :
        char data ;
        TrieNode* children[26];
        bool isTerminal;
        int freqCount;

        TrieNode(char ch){
            this -> data = ch;
            for(int i = 0 ; i < 26 ; i++){
                children[i] = nullptr ;
            }
            this -> isTerminal = false;
            this -> freqCount = 0 ;
        }
};

class Solution {
public:
    typedef pair<int , string> P; 

    class compare{
        public:
            bool operator()(P& a , P& b){
                if(a.first == b.first){
                    return a.second < b.second ;
                }

                return a.first > b.first ;
            }
    };

    void insertUtil(TrieNode* root , string& word , int i){
        if(i == word.size()){
            root -> freqCount++;
            root -> isTerminal = true;
            return ;
        }

        int index = word[i] - 'a';
        if(!root -> children[index]){
            root -> children[index] = new TrieNode(word[i]);
        }

        insertUtil(root -> children[index], word , i+1);
    }

    void traverse(TrieNode* root , priority_queue<P, vector<P> , compare>& minHeap , int k , string word){
        if(!root) return ;

        if(root -> isTerminal){
            minHeap.push({root -> freqCount , word});
            if(minHeap.size() > k) minHeap.pop();
        }

        for(int i = 0 ; i < 26 ; i++){
            if(root -> children[i]){
                char ch = i + 'a';
                traverse(root -> children[i] , minHeap, k , word + ch);
            }
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        TrieNode* root = new TrieNode('-');    
        for(auto &word : words){
            insertUtil(root , word , 0);
        }

        priority_queue<P, vector<P> , compare> minHeap ;
        traverse(root , minHeap, k, "");

        vector<string> ans ;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // as min heap of top k frequent word and top most is last in top k
        reverse(ans.begin(), ans.end()); 

        return ans;
    }
};