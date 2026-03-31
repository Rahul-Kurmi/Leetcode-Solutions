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
    vector<int> inorderTraversal(TreeNode* root){
        if(!root) return {} ;

        vector<int> leftAns = inorderTraversal(root -> left);
        vector<int> rightAns = inorderTraversal(root -> right);

        leftAns.push_back(root -> val);
        leftAns.insert(leftAns.end() , rightAns.begin() , rightAns.end());
        return leftAns ;
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root);
        for(int i = 1 ; i < inorder.size() ; i++){
            if(inorder[i-1] >= inorder[i]) return false ;
        }
        return true ;
    }
};