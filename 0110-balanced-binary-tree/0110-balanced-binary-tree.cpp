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
    int calculateTreeHeight(TreeNode*& root){
        if(root == nullptr) return 0;

        int leftHeight = calculateTreeHeight(root -> left);
        int rightHeight = calculateTreeHeight(root -> right);

        return max(leftHeight , rightHeight) + 1 ;
    }

    bool isBalanced(TreeNode*& root) {
        if(root == nullptr) return true ;

        // Calculate current root is balances of not 
        int leftHeight = calculateTreeHeight(root -> left);
        int rightHeight = calculateTreeHeight(root -> right);

        bool ans = abs(leftHeight - rightHeight) <= 1 ? true : false;

        // Calculate left subTree is balanced 
        bool leftBalanceCheck = isBalanced(root -> left);

        // Calculate right subTree is balanced
        bool rightBalanceCheck = isBalanced(root -> right);

        return ans && leftBalanceCheck && rightBalanceCheck ; 
    }
};