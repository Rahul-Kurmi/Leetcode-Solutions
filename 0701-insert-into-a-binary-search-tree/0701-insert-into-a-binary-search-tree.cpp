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
                return ;
            }
            else{
                insertIntoBSTHelper(root -> right , val);
            }
        }

        if(val < root -> val){
            if(root -> left == nullptr){
                TreeNode* newNode = new TreeNode(val);
                root -> left = newNode ;
                return ;
            }
            else{
                insertIntoBSTHelper(root -> left , val);
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            root = new TreeNode(val);
            return root ;
        }
        insertIntoBSTHelper(root , val);
        return root ;

    }
};