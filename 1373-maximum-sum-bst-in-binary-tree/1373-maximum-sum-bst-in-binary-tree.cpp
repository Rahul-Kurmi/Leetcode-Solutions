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

class NodeData {
public:
    int bstSum;
    int maxValue;
    int minValue;
    bool isBst;

    NodeData(int _bstSum, int _maxValue, int _minValue, bool _isBst)
        : bstSum(_bstSum),
          maxValue(_maxValue),
          minValue(_minValue),
          isBst(_isBst)
    {}
};

class Solution {
public:
    int maxSum = 0;

    NodeData maxSumBSTHelper(TreeNode* root){
        // Base case:
        // An empty tree is a valid BST with sum = 0.
        // maxValue = INT_MIN and minValue = INT_MAX act as neutral values
        // so comparisons at parent nodes work correctly.
        if(!root){
            return NodeData(0, INT_MIN, INT_MAX, true);
        }

        // Recursively get information from left and right subtrees
        NodeData leftAns = maxSumBSTHelper(root->left);
        NodeData rightAns = maxSumBSTHelper(root->right);

        NodeData curr(0, 0, 0, false);

        // Check if current subtree is a BST:
        // 1. Left subtree must be BST
        // 2. Right subtree must be BST
        // 3. Max value in left subtree < current node value
        // 4. Min value in right subtree > current node value
        if(root->val > leftAns.maxValue &&
           root->val < rightAns.minValue &&
           leftAns.isBst && rightAns.isBst){

            curr.isBst = true;

            // Sum of current BST = root + left subtree sum + right subtree sum
            curr.bstSum = root->val + leftAns.bstSum + rightAns.bstSum;

            // Update global maximum sum
            maxSum = max(maxSum, curr.bstSum);

            // Propagate values upward:
            // minValue → smallest value in this subtree (comes from left side)
            // maxValue → largest value in this subtree (comes from right side)
            curr.minValue = min(root->val, leftAns.minValue);
            curr.maxValue = max(root->val, rightAns.maxValue);
        }
        else{
            // If not a BST:
            // Mark as invalid so parent cannot consider this subtree as BST
            curr.isBst = false;
            curr.bstSum = 0;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};