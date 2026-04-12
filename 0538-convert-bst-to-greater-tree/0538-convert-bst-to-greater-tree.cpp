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
    int sum = 0;
    void convertBSTIntoGreaterTree(TreeNode* root){
        if(!root) return ;

        // move all the way to right --> as right is the biggest one
        convertBSTIntoGreaterTree(root -> right);

        sum += root -> val ;
        root -> val = sum ;

        // here we go to right first and get all greater sum
        convertBSTIntoGreaterTree(root -> left); 
    }

    TreeNode* convertBST(TreeNode* root) {
        convertBSTIntoGreaterTree(root);
        return root ;
    }
};