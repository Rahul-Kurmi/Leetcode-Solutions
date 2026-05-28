class TrieNode {
public:
    unordered_map<char, TrieNode*> children;

    pair<int,int> storeData; // {index, size}

    TrieNode(int idx, int sz) {
        storeData = {idx, sz};
    }

    ~TrieNode() {
        for (auto &it : children) {
            delete it.second;
        }
    }
};

class Solution {
public:

    void insertData(TrieNode* root, string &str, int strIndex) {

        TrieNode* node = root;

        for(char ch : str) {

            if(node->children.count(ch) == 0) {
                node->children[ch] =
                    new TrieNode(strIndex, str.size());
            }

            node = node->children[ch];

            if(node->storeData.second > str.size()) {
                node->storeData = {strIndex, (int)str.size()};
            }
        }
    }

    int findSuffix(TrieNode* root, string &str) {

        TrieNode* node = root;

        for(char ch : str) {

            if(node->children.count(ch) == 0) {
                return node->storeData.first;
            }

            node = node->children[ch];
        }

        return node->storeData.first;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        TrieNode* root = new TrieNode(INT_MAX, INT_MAX);

        // store globally shortest string
        for(int i = 0; i < wordsContainer.size(); i++) {

            string str = wordsContainer[i];

            if(root->storeData.second > str.size()) {
                root->storeData = {i, (int)str.size()};
            }

            reverse(str.begin(), str.end());

            insertData(root, str, i);
        }

        vector<int> ans;

        for(string str : wordsQuery) {

            reverse(str.begin(), str.end());

            ans.push_back(findSuffix(root, str));
        }

        delete root; // delte trieNode

        return ans;
    }
};