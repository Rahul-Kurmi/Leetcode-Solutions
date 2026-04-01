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
    TreeNode* ans = nullptr ;
    void kthSmallestHelper(TreeNode* root , int k , int& count){
        if(!root) return;

        kthSmallestHelper(root -> left , k , count);
        count++;
        if(k == count) ans = root ;
        kthSmallestHelper(root -> right , k , count);

    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0 ;
        kthSmallestHelper(root , k , count);
        return ans -> val ;    
    }
};