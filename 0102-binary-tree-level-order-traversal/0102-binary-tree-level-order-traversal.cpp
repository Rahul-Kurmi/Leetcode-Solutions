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
        // WITH FOR LOOP INSIDE --> SAME COMPLEXITY O(N)
        vector<vector<int>> ans ;
        if (root == nullptr) {
            return ans ;
        }
        
        vector<int> store ;
        queue<TreeNode*> q ;
        // Push root node 
        q.push(root);

        while(!q.empty()){
            store.clear(); // new level make this array empty 
            int qSize = q.size() ; // all current elements of this level
            for(int i = 0 ; i < qSize ; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);

                store.push_back(temp -> val);  
            } 
            ans.push_back(store); 
        }
        
        return ans;
    }
};