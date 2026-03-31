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
    void deleteNodeHelper(TreeNode*& root, int key){
        if(!root) return ;

        if(key < root -> val){
            deleteNodeHelper(root -> left , key);
        }
        else if(key > root -> val){
            deleteNodeHelper(root -> right , key);
        }
        else{
            // Case 1 : no child 
            if(!root -> left && !root -> right){
                root = nullptr ;
                return ;
            }
            // Case 2 : only right child 
            else if(!root -> left){
                root = root -> right ;
                return ;
            }
            // Case 3 : only left child 
            else if(!root -> right){
                root = root -> left ;
                return ;
            }
            // Case 4 : Both childs
            else{
                TreeNode* temp = root -> left ;
                while(temp -> right){
                    temp = temp -> right;
                }

                root -> val = temp -> val ;
                deleteNodeHelper(root -> left , temp -> val);
            }
        }

    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        deleteNodeHelper(root , key);
        return root ;
    }
};