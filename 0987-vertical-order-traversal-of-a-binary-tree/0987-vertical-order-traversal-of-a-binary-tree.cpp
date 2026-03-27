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
    void verticalTraversalHelper(TreeNode*& root , int hd , int lvl , map<int, map<int, multiset<int> >>& mp ){
        if(!root) return ;
        
        mp[hd][lvl].insert(root -> val);
        
        verticalTraversalHelper(root -> left , hd-1 , lvl+1, mp);
        verticalTraversalHelper(root -> right, hd+1 , lvl+1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int> >> mp ;

        verticalTraversalHelper(root, 0 , 0 , mp);

        vector<vector<int>> ans ;

        for(auto &col : mp){
            auto& levelMap = col.second ;
            vector<int> vertical ;
            for(auto &level : levelMap){
                auto& mSet = level.second ;
                vertical.insert(vertical.end() , mSet.begin() , mSet.end());
            }
            ans.push_back(vertical);
        }

        return ans;
    }
};