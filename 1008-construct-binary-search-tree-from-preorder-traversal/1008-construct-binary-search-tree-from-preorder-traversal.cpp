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
    TreeNode* buildBSTfromPreorder(vector<int>& preorder , int& i , int min , int max){
        if(i >= preorder.size()){
            return nullptr ;
        }

        TreeNode* root = nullptr ;
        if(preorder[i] > min && preorder[i] < max){
            root = new TreeNode(preorder[i++]);
            root -> left = buildBSTfromPreorder(preorder , i , min , root -> val);
            root -> right = buildBSTfromPreorder(preorder , i , root -> val , max);
        }

        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN ;
        int max = INT_MAX ;
        int i = 0 ;
        return buildBSTfromPreorder(preorder , i , min  , max) ;
    }
};