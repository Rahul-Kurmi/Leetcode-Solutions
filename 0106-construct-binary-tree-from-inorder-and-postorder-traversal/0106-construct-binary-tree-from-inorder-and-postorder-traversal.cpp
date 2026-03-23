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
    int findPosInorder(vector<int>& inorder , int element){
        for(int i = 0 ; i < inorder.size() ; i++){
            if(inorder[i] == element) return i ;
        }
        return -1 ;
    }

    TreeNode* buildTreeInorderPostorder(vector<int>& inorder, vector<int>& postorder, int& postIndex , int startInorder , int endInorder){
        if(postIndex < 0 || startInorder > endInorder) return nullptr ;

        int element = postorder[postIndex--];
        TreeNode* newRootNode = new TreeNode(element);
        int posInInorder = findPosInorder(inorder , element);

        newRootNode -> right = buildTreeInorderPostorder(inorder, postorder, postIndex, posInInorder+1 , endInorder);
        newRootNode -> left = buildTreeInorderPostorder(inorder, postorder, postIndex, startInorder, posInInorder-1);

        return newRootNode ;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1 ;
        return buildTreeInorderPostorder(inorder, postorder, postIndex, 0 , inorder.size() - 1);
    }
};