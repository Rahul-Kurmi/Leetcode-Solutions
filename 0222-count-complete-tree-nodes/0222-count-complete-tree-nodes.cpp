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
    int countNodes(TreeNode* root) {
        int count = 0 ;
        while(root != nullptr){
            if(!root -> left){
                count++;
                root = root -> right;
            }
            else{
                TreeNode* temp = root -> left ;
                while(temp -> right != root && temp -> right){
                    temp = temp -> right;
                }
                
                if(temp -> right == nullptr){
                    temp -> right = root;
                    root = root -> left;
                }
                else{
                    temp -> right = nullptr;
                    count++;
                    root = root -> right;
                }
            }
        }
        return count ;
    }
};