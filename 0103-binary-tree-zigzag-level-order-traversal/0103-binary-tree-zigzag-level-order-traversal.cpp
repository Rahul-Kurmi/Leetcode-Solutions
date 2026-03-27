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
        vector<int> store ;
        queue<TreeNode*> q ;
        q.push(root);
        q.push(nullptr) ;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == nullptr){
                ans.push_back(store);
                store.clear();
                if(!q.empty()) q.push(nullptr);
            }
            else{
                store.push_back(temp -> val);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }

        for(int i = 0 ; i < ans.size() ;  i++){
            if(i % 2){
                reverse(ans[i].begin() , ans[i].end());
            }
        }

        return ans ;
    }
};