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
    int calculateHeight(TreeNode* root){
        if(root == nullptr) return 0 ;

        int leftHeight = calculateHeight(root -> left);
        int rightHeight = calculateHeight(root -> right);

        int ans = max(leftHeight, rightHeight) + 1 ;

        return ans ;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0 ;

        // Left tree Diameter 
        int leftDiameter = diameterOfBinaryTree(root->left);

        // Right Tree Diameter 
        int rightDiameter = diameterOfBinaryTree(root->right);


        // Diameter of current tree with root 
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        int currDiameter = leftHeight + rightHeight;

        return max({leftDiameter, rightDiameter, currDiameter});
    }
};