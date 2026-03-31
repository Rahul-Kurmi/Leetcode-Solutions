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
    TreeNode* deleteNodeHelper(TreeNode* root, int key){
        if(!root) return nullptr ;

        if(key > root -> val){
            root -> right = deleteNodeHelper(root -> right , key);
        }
        else if(key < root -> val){
            root -> left = deleteNodeHelper(root -> left , key);
        }
        else{ // when root -> val == key
            // Case 1: no childs 
            if(!root -> left && !root -> right){
                return nullptr ;
            }
            // Case 2 : if right is null
            if(!root -> right){
                return root -> left ;
            }
            // Case 3: if left is null 
            if(!root -> left){
                return root -> right ;
            }
            // Case 4: both child present
            if(root -> left && root -> right){
                // find inorder predecessor 
                TreeNode* temp = root -> left ;
                while(temp -> right){
                    temp = temp -> right;
                }
                // replace value of root and inorder predecessor 
                root -> val = temp -> val ;
                // Delete that temp node
                root -> left = deleteNodeHelper(root -> left , temp -> val);
            }
        }
        return root ;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodeHelper(root , key);
    }
};