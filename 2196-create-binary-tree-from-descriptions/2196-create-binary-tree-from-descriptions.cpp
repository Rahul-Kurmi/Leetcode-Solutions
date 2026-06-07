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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> storeNodes ;
        unordered_set<int> childSet ; // they can never be root

        for(vector<int>& desc : descriptions){
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            if(storeNodes.count(parent) == 0){
                storeNodes[parent] = new TreeNode(parent);
            }

            if(storeNodes.count(child) == 0){
                storeNodes[child] = new TreeNode(child);
            }

            if(isLeft){
                storeNodes[parent] -> left =  storeNodes[child];
            }
            else{
                storeNodes[parent] -> right = storeNodes[child];
            }

            // insert child in childSet
            childSet.insert(child); 
        }  


        // find the node that is not present in childSet that is the root
        for(vector<int> &desc : descriptions){
            int parent = desc[0];

            if(childSet.count(parent) == 0){
                return storeNodes[parent];
            }
        }

        return nullptr; // we will never reach here
    }
};