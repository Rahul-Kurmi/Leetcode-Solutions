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
    int count = 0 ;
    pair<int, int> solve(TreeNode* node){
        if(node == nullptr) return {0 ,0};

        if(!node -> left && !node -> right){
            count++;
            return {1, node -> val} ; // count , sum
        }

        auto left = solve(node -> left);
        auto right = solve(node -> right);

        int totalCount = left.first + right.first + 1 ;
        int totalSum = left.second + right.second + node -> val ;

        if((totalSum / totalCount) == node -> val) count++;

        return {totalCount, totalSum} ;

    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);

        return count ;
    }
};