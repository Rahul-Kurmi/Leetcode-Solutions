/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void createBinaryTreeHelper(vector<vector<int>>& descriptions, unordered_map<int, TreeNode*> &findNode, unordered_map<TreeNode* , bool>& isParent){

        for(auto &desc : descriptions){
            bool isLeft = desc[2];
            if(isLeft){
                TreeNode* root ;
                TreeNode* child ; 
                if(findNode.find(desc[0]) == findNode.end()){
                    root = new TreeNode(desc[0]);
                    findNode[desc[0]] = root ;
                }
                else{
                    root = findNode[desc[0]];
                }

                if(findNode.find(desc[1]) == findNode.end()){
                    child = new TreeNode(desc[1]);
                    findNode[desc[1]] = child;
                }
                else{
                    child = findNode[desc[1]];
                }

                isParent[child] = true ;
                
                if(isParent[root] != true){
                    isParent[root] = false ;
                }

                root -> left = child ;
            }
            else{
                TreeNode* root ;
                TreeNode* child ; 
                if(findNode.find(desc[0]) == findNode.end()){
                    root = new TreeNode(desc[0]);
                    findNode[desc[0]] = root ;
                }
                else{
                    root = findNode[desc[0]];
                }

                if(findNode.find(desc[1]) == findNode.end()){
                    child = new TreeNode(desc[1]);
                    findNode[desc[1]] = child;
                }
                else{
                    child = findNode[desc[1]];
                }

                isParent[child] = true ;
                
                if(isParent[root] != true){
                    isParent[root] = false ;
                }
                
                root -> right = child ;
            }
        }

    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> findNode;
        unordered_map<TreeNode* , bool> isParent ;

        createBinaryTreeHelper(descriptions , findNode, isParent);

        TreeNode* root = nullptr ;
        for(auto it : isParent){
            if(it.second == false){
                root = it.first;
            }
        }

        return root ;
    }
};