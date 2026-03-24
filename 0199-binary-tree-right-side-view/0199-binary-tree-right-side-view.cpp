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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {} ;
        vector<int> ans ;

        // map will store the first node of each level
        // As here we will move to right node first 
        map<int, int> rightFirstNode;
        
        // this queue stores the pair of node and level 
        // here level helps in finding whether it is stored in map or not    
        queue<pair<TreeNode*, int>> q ;
        q.push(make_pair(root , 0)); // store root ie. at level 0

        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();

            // Extract Node and level from temp
            TreeNode* frontNode = temp.first ;
            int nodeLevel = temp.second;

            // check if this level is present in map or not 
            // if not present then insert level and node value 
            if(rightFirstNode.find(nodeLevel) == rightFirstNode.end()){
                rightFirstNode[nodeLevel] = frontNode -> val ;
            }

            // first traverse RIGHT SIDE 
            if(frontNode -> right){
                q.push(make_pair(frontNode -> right, nodeLevel+1));
            }

            // then traverse LEFT 
            if(frontNode -> left){
                q.push(make_pair(frontNode -> left , nodeLevel+1));
            }
        }

        // Now we have all the level rightmost value in map 
        for(auto it : rightFirstNode){
            ans.push_back(it.second);
        }

        return ans ;
    }
};