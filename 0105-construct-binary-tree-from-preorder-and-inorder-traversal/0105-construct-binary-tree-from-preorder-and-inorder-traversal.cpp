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


    int findInorderPosition(vector<int>& inorder , int element){
        for(int i = 0 ; i < inorder.size() ; i++){
            if(inorder[i] == element) return i ;
        }

        // This return doesn't effect anything
        return -1 ;
    }

    TreeNode* buildTreeFromInorderPreOrder(vector<int>& preorder, vector<int>& inorder , int& preIndex , int startInorder , int endInorder){
        if(preIndex >= preorder.size() || startInorder > endInorder){
            return nullptr ;
        }

        int element = preorder[preIndex++];
        TreeNode* newRootNode = new TreeNode(element);
        int posInInorder = findInorderPosition(inorder , element);

        newRootNode -> left = buildTreeFromInorderPreOrder(preorder, inorder, preIndex, startInorder, posInInorder - 1);
        newRootNode -> right = buildTreeFromInorderPreOrder(preorder, inorder, preIndex, posInInorder + 1 , endInorder);

        return newRootNode ;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0 ;
        TreeNode* finalAns = buildTreeFromInorderPreOrder(preorder, inorder, preIndex, 0 , inorder.size() - 1);
        return finalAns ;
    }
};