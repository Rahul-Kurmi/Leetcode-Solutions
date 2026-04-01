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

    pair<int , TreeNode*> lcaDeepestLeaveshelper(TreeNode* root){
        if(!root) return { 0 , nullptr} ;

        auto leftAns = lcaDeepestLeaveshelper(root -> left);
        auto rightAns = lcaDeepestLeaveshelper(root -> right);

        int leftDepth = leftAns.first ;
        int rightDepth = rightAns.first ;
        if(leftDepth == rightDepth){
            return {leftDepth + 1 , root};
        }
        if(leftDepth > rightDepth){
            return {leftDepth + 1 , leftAns.second};
        }
        if(rightDepth > leftDepth){
            return {rightDepth + 1 , rightAns.second};
        }
        return {0 , nullptr} ;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto pairHeightLCA = lcaDeepestLeaveshelper(root);
        return pairHeightLCA.second ;
    }
};