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
    int sum = 0 ;
    void rangeSumBSTHelper(TreeNode* root, int low, int high){
        if(!root) return ;

        if(root -> val >= low && root -> val <= high){
            sum += root -> val ;
            rangeSumBSTHelper(root -> left , low , high);
            rangeSumBSTHelper(root -> right , low , high);
        }
        else if(root -> val < low){
            rangeSumBSTHelper(root -> right , low , high);
        }
        else{
            rangeSumBSTHelper(root -> left , low , high);
        }
    } 

    int rangeSumBST(TreeNode* root, int low, int high) {
        rangeSumBSTHelper(root , low , high);
        return sum ;
    }
};