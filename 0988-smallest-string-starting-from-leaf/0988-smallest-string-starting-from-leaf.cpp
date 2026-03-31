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
    void smallestFromLeafhelper(TreeNode* root , string curr, string& ans){
        if(!root ) return ;

        // prepend current char (leaf → root direction)
        curr = char(root-> val + 'a') + curr ;

        // if leaf node
        if(!root->left && !root->right){
            if(ans == "" || curr < ans){
                ans = curr;
            }
        }

        smallestFromLeafhelper(root -> left , curr, ans);
        smallestFromLeafhelper(root -> right , curr, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "" ;
        smallestFromLeafhelper(root , "" , ans);
        return ans ;
    }
};