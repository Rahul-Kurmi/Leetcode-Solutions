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
    vector<vector<int>> ans;

    void pathSumHelper(TreeNode* root, int &targetSum, vector<int>& store){
        if(root == nullptr) return;

        // choose
        // HERE BOTH ARE PASS BY REFERENCE
        store.push_back(root->val);
        targetSum -= root->val;

        // check leaf
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == 0){
                ans.push_back(store);
            }
        }

        // explore
        pathSumHelper(root->left, targetSum, store);
        pathSumHelper(root->right, targetSum, store);

        // backtrack (VERY IMPORTANT)
        store.pop_back();
        targetSum += root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> store;
        pathSumHelper(root, targetSum, store);
        return ans;
    }
};