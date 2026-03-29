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
    string preorderEncoding(TreeNode* root , unordered_map<string, int>& mp,   vector<TreeNode*> &res){
        if(root == nullptr)  return "N";

        string encode = to_string(root -> val) + "," + 
                        preorderEncoding(root -> left , mp , res) + "," +
                        preorderEncoding(root -> right, mp , res);
        
        if(mp[encode] == 1){
            res.push_back(root);
        }

        mp[encode]++;

        return encode ;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp ;
        vector<TreeNode*> res ;
        preorderEncoding(root , mp , res);
        return res ;

    }
};