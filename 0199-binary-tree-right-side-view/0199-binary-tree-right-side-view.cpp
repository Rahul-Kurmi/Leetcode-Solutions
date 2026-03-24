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
    // If we call left recursion first in right view then code is like this 
    
    void rightSideViewRecursion(TreeNode* &root, int level, vector<int>& ans){
        if(root == nullptr) return ;

        // means we have nott stored a node value at this level 
        if(ans.size() == level){
            ans.push_back(root -> val);
        }
        else{
            // as moving left to right thus we'll find rightmost at last
            // Thus change value when came at same level to get rightmos 
            ans[level] = root -> val ;
        }

        // moving left first 
        rightSideViewRecursion(root -> left, level + 1 , ans);

        // move right next
        rightSideViewRecursion(root -> right , level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans ;
        rightSideViewRecursion(root , 0 , ans);
        return ans ;
    }
};