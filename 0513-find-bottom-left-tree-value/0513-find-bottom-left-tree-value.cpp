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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q ;
        int ans = root -> val;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == nullptr){
                if(!q.empty()){
                    ans = q.front() -> val ;
                    q.push(nullptr);
                }
            }else{
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }
        return ans;
    }
};