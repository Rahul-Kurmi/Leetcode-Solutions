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
    int maxDiameter = 0 ;
    int findDiameterWithHeight(TreeNode*& root){
        if(root == nullptr) return 0 ;

        int leftHeight = findDiameterWithHeight(root -> left);
        int rightHeight = findDiameterWithHeight(root -> right);

        // get curr diameter
        int currDiameter = leftHeight + rightHeight;
        // update maxDiameter 
        maxDiameter = max(currDiameter , maxDiameter);

        // return current height
        return max(leftHeight , rightHeight) + 1 ;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        findDiameterWithHeight(root);
        return maxDiameter ;
    }
};