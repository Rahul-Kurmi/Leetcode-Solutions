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
    int totalCount(TreeNode* root){
        int count = 0 ;
        queue<TreeNode*>q ;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            count++;

            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        return count ;
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = totalCount(root);
        // Node and their index 
        queue<pair<TreeNode* , int>> q ;
        q.push({root , 0});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* tempNode = temp.first ;
            int tempIndex = temp.second ;
            if(tempIndex >= totalNodes) return false ;

            if(tempNode -> left){
                q.push({tempNode -> left , 2*tempIndex + 1});
            }
            if(tempNode -> right){
                q.push({tempNode -> right , 2*tempIndex + 2});
            }
        }
        return true ;
    }
};