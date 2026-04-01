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
    void Store_Inorder(TreeNode* root , vector<int> &Store){
        if(root == NULL) {
            return ;
        }
        
        // LNR
        Store_Inorder(root -> left , Store) ;
        Store.push_back(root -> val) ;
        Store_Inorder(root -> right , Store) ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> Store;
        Store_Inorder(root , Store) ;
        int i = 0 ;
        int ans ;
        while(k--){
            ans = Store[i] ;
            i++ ;
        }
        
        return ans ;
    }
};