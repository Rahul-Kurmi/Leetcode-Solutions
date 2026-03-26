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
    bool isSymmetricCheck(TreeNode*& root1 , TreeNode*& root2){
        if(!root1 && !root2){ // both nullptr
            return true ;
        }

        if(root1 && root2){ // Both not nullptr
            return (root1 -> val == root2 -> val) 
                && isSymmetricCheck(root1 -> left , root2 -> right)
                && isSymmetricCheck(root1 -> right , root2 -> left);
        }

        // one nullptr one not
        return false ;
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetricCheck(root -> left , root -> right);
    }
};