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
    void pathSumHelper(TreeNode*& root , ll target , int& count){
        if(root == nullptr) return ;
        target -= root -> val ;
        if(target == 0){
            count++;
        }
        pathSumHelper(root -> left , target , count);
        pathSumHelper(root -> right, target , count);
    }

    void pathSumSolution(TreeNode*& root , ll targetSum , int &count){
        if(!root) return ;

        pathSumHelper(root , targetSum , count);

        pathSumSolution(root -> left , targetSum , count);
        pathSumSolution(root -> right, targetSum , count);
    }

    int pathSum(TreeNode* root, ll targetSum) {
        int count = 0 ;
        pathSumSolution(root , targetSum , count);
        return count ;

    }
};