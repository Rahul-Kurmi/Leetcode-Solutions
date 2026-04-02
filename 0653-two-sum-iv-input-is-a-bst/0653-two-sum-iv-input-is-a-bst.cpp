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

    bool checking(TreeNode* root , TreeNode* current , int value){
        if(!root) return false ;

        if(root -> val == value && root != current) return true ;

        return checking(root -> left , current , value) || 
               checking(root -> right , current , value) ; 
    }

    bool traverseAndFind(TreeNode* root, TreeNode* current , int k){
        if(!current) return false ;

        int value = k - current -> val ;

        if(checking(root , current , value)){
            return true ;
        } 

        return traverseAndFind(root , current -> left , k) || 
               traverseAndFind(root, current -> right , k) ; 
    }

    bool findTarget(TreeNode* root, int k) {
        return traverseAndFind(root , root, k);
    }
};