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
    TreeNode* findAncestor(TreeNode* root , TreeNode* p , TreeNode* q){
        if(!root) return nullptr ;

        if(root == p) return root ;
        if(root == q) return root ;

        TreeNode* leftAns = findAncestor(root -> left , p , q);
        TreeNode* rightAns = findAncestor(root -> right , p , q);

        if(!leftAns && !rightAns) return nullptr ;
        if(leftAns && !rightAns) return leftAns ;
        if(!leftAns && rightAns) return rightAns ;
        return root ;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> store ;
        queue<TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
            store.clear();
            int qSize = q.size();
            for(int i = 0 ; i < qSize ; i++){
                store.push_back(q.front());
                if(q.front() -> left) q.push(q.front() -> left);
                if(q.front() -> right)q.push(q.front() -> right);
                q.pop();
            }
        }

        if(store.size() == 1) return store[0];
        return findAncestor(root , store[0] , store[store.size() - 1]);
    }
};