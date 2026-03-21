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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0 ;
        int maxDepth = 0 ;
        queue<TreeNode* > q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* temp = q.front() ;
            q.pop();

            if(temp == nullptr){
                maxDepth++;
                if(!q.empty())q.push(nullptr);
            }
            else{
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }
        return maxDepth ;
    }
};