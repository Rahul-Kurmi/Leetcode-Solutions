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
    void insertIntoBSTHelper(TreeNode* &root , int val){
        if(root == nullptr) return ;

        if(val > root -> val){
            if(root -> right == nullptr){
                TreeNode* newNode = new TreeNode(val);
                root -> right = newNode ;
            }
            else{
                insertIntoBSTHelper(root -> right , val);
            }
        }

        if(val < root -> val){
            if(root -> left == nullptr){
                TreeNode* newNode = new TreeNode(val);
                root -> left = newNode ;
            }
            else{
                insertIntoBSTHelper(root -> left , val);
            }
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1 ; i < preorder.size() ; i++){
            insertIntoBSTHelper(root , preorder[i]);
        }

        return root ;
    }
};