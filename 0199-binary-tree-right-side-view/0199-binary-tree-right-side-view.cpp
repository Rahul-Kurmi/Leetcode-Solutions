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

        // map will store nodes of each level 
        map<int, int> nodeLevelMap;
        
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
            if(nodeLevelMap.find(nodeLevel) == nodeLevelMap.end()){
                nodeLevelMap[nodeLevel] = frontNode -> val ;
            }
            else{ // if found again at same level then it's rightmost 
            // change the value at that level
                nodeLevelMap[nodeLevel] = frontNode -> val ;
            }


            // here taking left node first, but question asked right view
            // thus we will store last level value in map
            if(frontNode -> left){
                q.push(make_pair(frontNode -> left , nodeLevel+1));
            }

            if(frontNode -> right){
                q.push(make_pair(frontNode -> right, nodeLevel+1));
            }
        }

        // Now we have all the level rightmost value in map 
        for(auto it : nodeLevelMap){
            ans.push_back(it.second);
        }

        return ans ;
    }
};