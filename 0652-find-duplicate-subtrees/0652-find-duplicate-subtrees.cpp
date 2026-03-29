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
    vector<TreeNode* > ans ;
    unordered_map<string , int> subTreeMap ;

    string preorderEncoding(TreeNode* root){
        if(root == nullptr) return "N" ;

        string currEncode = to_string(root -> val);
        string leftEncode = preorderEncoding(root -> left);
        string rightEncode = preorderEncoding(root -> right);
        string finalEncode = currEncode + "," + leftEncode + "," + rightEncode;

        // we find that this encoding is present in map
        if(subTreeMap.find(finalEncode) != subTreeMap.end()){
            // means this is our second encounter and it was found once before
            if(subTreeMap[finalEncode] == 1){
                // push back in ans as identical
                ans.push_back(root);
                subTreeMap[finalEncode]++;
            }
            else{
                // Encountered more than once means we have already pushed it into the map
                // just increase it 
                subTreeMap[finalEncode]++;;
            }
        }
        else{
            // means not in map first encounter 
            subTreeMap[finalEncode] = 1 ;
        }

        return finalEncode ;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorderEncoding(root);
        return ans ;
    }
};