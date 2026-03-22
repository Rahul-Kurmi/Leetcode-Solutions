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
   bool hasPathSumHelper(TreeNode* root, int targetSum, int currSum){

        // Base case: null node → no valid path
        if(root == nullptr){
            return false;
        }

        // Leaf node: check if path sum matches
        if(root->left == nullptr && root->right == nullptr){
            return targetSum == (currSum + root->val);
        }

        bool leftCheck = hasPathSumHelper(root->left, targetSum , currSum + root->val);
        bool rightCheck = hasPathSumHelper(root->right, targetSum, currSum + root->val);

        return leftCheck || rightCheck;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumHelper(root , targetSum , 0);
    }
};