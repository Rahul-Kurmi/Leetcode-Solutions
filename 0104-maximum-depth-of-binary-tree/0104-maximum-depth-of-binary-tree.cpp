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
    void maxDepthHelper(TreeNode*& root , int currHeight, int& maxHeight){
        if(root == nullptr){
            maxHeight = max(currHeight, maxHeight);
            return ;
        }

        maxDepthHelper(root -> left , currHeight+1, maxHeight);
        maxDepthHelper(root -> right , currHeight+1 , maxHeight);
    }

    int maxDepth(TreeNode* root) {
        int maxHeight = 0 ;
        maxDepthHelper(root , 0 , maxHeight);
        return maxHeight ;
    }
};