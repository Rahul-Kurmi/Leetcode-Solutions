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
    void sumNumbersHelper(TreeNode*& root , string store , int& ans){
        // If nullptr so return 
        if(root == nullptr){
            return ;
        }

        // Sum first as when reached leaf node we have to add that value as well
        store += to_string(root -> val) ;
        // use to_string as value can be 23 so root -> val - '0' will not work

        // If Leaf Node is found 
        if(root -> left == nullptr && root -> right == nullptr){
            ans += stoi(store);
            return ;
        }

        sumNumbersHelper(root -> left , store , ans);
        sumNumbersHelper(root -> right , store , ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0 ;
        sumNumbersHelper(root , "" , ans);
        return ans ;
    }
};