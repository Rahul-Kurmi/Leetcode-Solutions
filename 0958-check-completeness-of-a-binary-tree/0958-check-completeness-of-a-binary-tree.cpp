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

    int countNodes(TreeNode* root){
        if(!root) return 0 ;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }

    bool isCompleteTreeHelper(TreeNode* root , int index , int totalNodes){
        if(!root) return true ;
        if(index >= totalNodes) return false ;

        bool leftCheck = isCompleteTreeHelper(root -> left , 2*index+1 , totalNodes);
        bool rightCheck = isCompleteTreeHelper(root -> right , 2*index+2 , totalNodes);
        return leftCheck && rightCheck ;
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return isCompleteTreeHelper(root , 0 , totalNodes);
    }
};