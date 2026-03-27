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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        vector<vector<int>> ans ;

        queue<TreeNode*> q ;
        q.push(root);

        bool leftToRight = true ;

        while(!q.empty()){
            int qSize = q.size();
            vector<int> store(qSize) ;
            for(int i = 0 ; i < qSize ; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(leftToRight){
                    store[i] = temp -> val;
                }
                else{
                    store[store.size() - i - 1] = temp -> val ;
                }
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            ans.push_back(store);
            leftToRight = !leftToRight ;
        }

        return ans ;
    }
};