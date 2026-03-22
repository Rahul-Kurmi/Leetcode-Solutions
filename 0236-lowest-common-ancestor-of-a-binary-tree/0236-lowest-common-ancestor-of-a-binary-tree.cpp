/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr ;

        if(root == p || root == q) return root ;

        TreeNode* leftAns = lowestCommonAncestor(root -> left , p , q);
        TreeNode* rightAns = lowestCommonAncestor(root -> right, p  , q);

        // p and q found in different subtrees → current node is LCA
        if(leftAns && rightAns) return root ;

        // If only one side is non-null, return that side
        // → Either:
        //    1. One node (p or q) found in subtree
        //    2. One node is ancestor of the other
        return leftAns ? leftAns : rightAns ;

    }
};