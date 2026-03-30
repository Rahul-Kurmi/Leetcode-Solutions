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
    int findMaxIndex(vector<int>& nums, int start , int end){
        int maxi = start ;
        for(int i = start + 1 ; i <= end ; i++){
            if(nums[i] > nums[maxi]){
                maxi =  i ;
            }
        }
        return maxi ;
    }

    TreeNode* solve(int start , int end , vector<int>& nums){
        if(start > end) return nullptr ;
        
        int maxIndex = findMaxIndex(nums , start , end);
        TreeNode* root = new TreeNode(nums[maxIndex]);

        root -> left = solve(start , maxIndex - 1 , nums);
        root -> right = solve(maxIndex + 1 , end , nums ); 
        return root ;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0 , nums.size() - 1, nums);
    }
};