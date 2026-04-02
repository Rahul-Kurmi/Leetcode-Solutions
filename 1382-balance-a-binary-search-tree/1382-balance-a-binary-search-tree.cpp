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
    void getInorder(TreeNode* root , vector<int>& inorder){
        if(!root) return ;

        getInorder(root -> left , inorder);
        inorder.push_back(root -> val);
        getInorder(root -> right , inorder);
    }    

    TreeNode* createBalanceBST(vector<int>& inorder , int inStart , int inEnd){
        if(inStart > inEnd) return nullptr ;

        int mid = inStart + (inEnd - inStart) / 2 ;
        TreeNode* root = new TreeNode(inorder[mid]);

        root -> left = createBalanceBST(inorder , inStart , mid - 1);
        root -> right = createBalanceBST(inorder , mid + 1 , inEnd);

        return root ;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder ;
        getInorder(root , inorder);
        return createBalanceBST(inorder , 0 , inorder.size() - 1);
    }
};