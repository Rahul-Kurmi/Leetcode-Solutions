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
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(!root) return ;
        inorderTraversal(root -> left, inorder);
        inorder.push_back(root -> val);
        inorderTraversal(root -> right, inorder);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> inorder ;
        inorderTraversal(root , inorder);

        int sum = 0 ;
        for(int i = 0 ; i < inorder.size() ; i++){
            if(inorder[i] >= low){
                while(i < inorder.size() && inorder[i] <= high){
                    sum += inorder[i];
                    i++;
                }
                return sum ;
            }
        }
        return sum ;
    }
};