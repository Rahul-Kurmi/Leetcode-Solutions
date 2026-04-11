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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool isNonFullNode = false ;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp -> left){
                if(isNonFullNode) return false ;
                q.push(temp -> left);
            }else{
                isNonFullNode = true ;
            }

            if(temp -> right){
                if(isNonFullNode) return false ;
                q.push(temp -> right);
            }else{
                isNonFullNode = true ;
            }
        }

        return true ;
    }
};