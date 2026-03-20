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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;   // Final result storing level-wise nodes
        
        // Edge case: if tree is empty
        if(root == nullptr) return ans;
        
        queue<TreeNode*> q;
        
        // Push root and a NULL marker to indicate end of first level
        q.push(root);
        q.push(nullptr);

        vector<int> store; // Stores nodes of current level
        
        while(!q.empty()){

            // Add current node value to current level
            store.push_back(q.front()->val);

            // Push left child if exists
            if(q.front()->left){
                q.push(q.front()->left);
            }

            // Push right child if exists
            if(q.front()->right){
                q.push(q.front()->right);
            }

            // Remove current node from queue
            q.pop();

            // If next element is NULL → level completed
            if(q.front() == nullptr){
                
                // Remove NULL marker
                q.pop();

                // Store current level in answer
                ans.push_back(store);

                // Clear for next level
                store.clear();

                // if queue empty then last level
                if(!q.empty()) q.push(nullptr);
            }
        }
        
        return ans;
    }
};