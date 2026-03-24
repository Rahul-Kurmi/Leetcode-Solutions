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
    void rightSideViewRecursion(TreeNode* &root, int level, vector<int>& ans){
        if(root == nullptr) return ;

        // this means that at this level no rightmost node is found
        if(ans.size() == level){
            ans.push_back(root -> val);
        }

        // move right first 
        rightSideViewRecursion(root -> right , level + 1, ans);

        // move left next 
        rightSideViewRecursion(root -> left, level + 1 , ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans ;
        rightSideViewRecursion(root , 0 , ans);
        return ans ;
    }
};