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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false ;

        if(root -> left == nullptr && root -> right == nullptr){
            return targetSum == root -> val ;
            // here at leaf node targetSum will not be zero because the leaf Node value is not taken yet  
            // return targetSum == 0 + root-> val ;
        }

        targetSum -= root -> val ;
        
        bool leftCheck = hasPathSum(root -> left , targetSum);
        bool rightCheck = hasPathSum(root -> right , targetSum);

        return leftCheck || rightCheck ;
    }
};