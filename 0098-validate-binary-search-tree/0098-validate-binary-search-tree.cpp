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
    using ll = long long;

    bool isValidBSTHelper(TreeNode* root , ll lowerBound , ll upperBound){
        if(!root) return true ;

        bool currNodeCheck = (root -> val > lowerBound) && (root -> val < upperBound);

        bool leftCheck = isValidBSTHelper(root -> left , lowerBound , root -> val);
        bool rightCheck = isValidBSTHelper(root -> right, root -> val , upperBound);

        return currNodeCheck && leftCheck && rightCheck;

        
    }

    bool isValidBST(TreeNode* root) {
        ll lb = LLONG_MIN ;
        ll ub = LLONG_MAX ;
        return isValidBSTHelper(root , lb , ub);
    }
};