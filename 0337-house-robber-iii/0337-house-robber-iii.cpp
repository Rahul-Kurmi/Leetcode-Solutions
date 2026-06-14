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
    int robHelper(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(root == nullptr) return 0 ;

        if(dp.find(root) != dp.end()){
            return dp[root];
        }

        int robThisHouse = 0, dontRobThisHouse = 0 ;
        // robbing current House
        robThisHouse += root -> val  ;
        if(root -> left){
            robThisHouse += robHelper(root-> left-> left, dp) + robHelper(root-> left-> right, dp);
        }
        if(root -> right){
            robThisHouse += robHelper(root-> right-> left, dp) + robHelper(root-> right-> right, dp);
        }

        // Not robbing current house
        dontRobThisHouse = robHelper(root -> left, dp) + robHelper(root -> right, dp);

        return dp[root] =  max(robThisHouse , dontRobThisHouse);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp ;
        return robHelper(root, dp);
    }
};