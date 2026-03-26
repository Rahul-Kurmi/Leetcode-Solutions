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

    bool isTreeBalanced = true ;

    int checkBalancedWithHeight(TreeNode* root){
        if(!root) return 0 ;

        int lh = checkBalancedWithHeight(root -> left);
        int rh = checkBalancedWithHeight(root -> right);

        bool isCurrBalanced = abs(lh - rh) <= 1;
        isTreeBalanced = isCurrBalanced && isTreeBalanced ;

        return max(lh , rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        checkBalancedWithHeight(root);
        return isTreeBalanced ;
    }
};