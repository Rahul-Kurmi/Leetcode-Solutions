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
        // Base case 
        if(root == NULL) return NULL ;

        // check if node is p or q 
        if(root == p) return p ;
        if(root == q) return q ;

        TreeNode* left_ans = lowestCommonAncestor(root -> left , p , q) ;
        TreeNode* right_ans = lowestCommonAncestor(root -> right , p , q);

        if(left_ans == NULL && right_ans == NULL) return NULL ;
        else if(left_ans != NULL && right_ans == NULL) return left_ans;
        else if(left_ans == NULL && right_ans != NULL) return right_ans ;
        // if(left_ans != NULL && right_ans != NULL)
        else return root ;
    }
};