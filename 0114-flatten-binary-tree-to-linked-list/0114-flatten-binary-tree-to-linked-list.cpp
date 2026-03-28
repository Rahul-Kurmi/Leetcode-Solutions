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
    void flatten(TreeNode* root) {
        TreeNode* temp = root;

        while(temp != nullptr){
            if(!temp -> left ){
                temp = temp -> right;
            }
            else{
                TreeNode* tempRight = temp -> right ;
                TreeNode* tempLeft = temp -> left ;
                temp -> left = nullptr ;
                temp -> right = tempLeft ;
                temp = tempLeft ;
                while(tempLeft -> right){
                    tempLeft = tempLeft -> right ;
                }
                tempLeft -> right = tempRight;
            }
        }
    }
};