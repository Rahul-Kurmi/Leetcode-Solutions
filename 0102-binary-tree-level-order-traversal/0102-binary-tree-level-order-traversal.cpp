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
vector<vector<int>> levelOrderTraversal(TreeNode* root){
    vector<vector<int>> ans ;
    if (root == nullptr) {
        return ans ;
    }
    
    vector<int> store ;
    queue<TreeNode*> q ;
    // Push root node 
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        // If NULL → level finished
        if(node == nullptr){
            ans.push_back(store);
            store.clear();

            if(!q.empty()) q.push(nullptr);
        }
        else{
            // Add current node value
            store.push_back(node->val);

            // Push children
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ans ;
}


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return levelOrderTraversal(root) ;
    }
};