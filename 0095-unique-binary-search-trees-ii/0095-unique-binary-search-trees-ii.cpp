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

    vector<TreeNode*> solve(int start , int end, map<pair<int,int> , vector<TreeNode*>>& mp){
        if(start > end){
            return {nullptr} ;
        }

        if(start == end){
            return {new TreeNode(start)};
        }

        if(mp.find({start , end}) != mp.end()) return mp[{start , end}];

        vector<TreeNode*> ans ;
        for(int i = start ; i <= end ; i++){
            vector<TreeNode*> left_bst = solve(start , i-1, mp);
            vector<TreeNode*> right_bst = solve(i+1 , end, mp);

            for(int j = 0 ; j < left_bst.size(); j++){
                for(int k = 0 ; k < right_bst.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root -> left = left_bst[j];
                    root -> right = right_bst[k];
                    ans.push_back(root);
                }
            }
        }

        return mp[{start , end}] =  ans ;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int> , vector<TreeNode*>> mp; 
        return solve(1, n, mp);
    }
};