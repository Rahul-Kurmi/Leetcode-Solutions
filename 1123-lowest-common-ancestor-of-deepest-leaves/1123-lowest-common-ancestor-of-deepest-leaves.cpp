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
    unordered_map<TreeNode*, int> NodeDepth;
    int maxDepth = 0;

    void calculateEachDepth(TreeNode* root, int d) {
        if (!root) return;

        NodeDepth[root] = d;
        maxDepth = max(d, maxDepth);

        calculateEachDepth(root->left, d + 1);
        calculateEachDepth(root->right, d + 1);
    }

    TreeNode* lcaDeepestLeavesHelper(TreeNode* root) {
        if (!root) return nullptr;

        if (NodeDepth[root] == maxDepth) return root;

        TreeNode* leftAns = lcaDeepestLeavesHelper(root->left);
        TreeNode* rightAns = lcaDeepestLeavesHelper(root->right);

        if (!leftAns && !rightAns) return nullptr;
        if (leftAns && !rightAns) return leftAns;
        if (!leftAns && rightAns) return rightAns;

        return root;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        calculateEachDepth(root, 0);

        return lcaDeepestLeavesHelper(root);
    }
};