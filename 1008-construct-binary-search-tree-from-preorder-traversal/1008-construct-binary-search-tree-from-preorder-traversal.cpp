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
    TreeNode* BSTCreation(TreeNode*& root , int data){
        if(root == nullptr){
            root = new TreeNode(data);
            return root ;
        }

        // left connection 
        if(root -> val > data){
            root -> left = BSTCreation(root -> left , data);
        }

        // right connection
        if(root -> val < data){
            root -> right = BSTCreation(root -> right, data);
        }

        return root ;
    } 

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr ;
        for(int i = 0 ; i < preorder.size(); i++){
            BSTCreation(root , preorder[i]);
        }
        return root ;
    }
};