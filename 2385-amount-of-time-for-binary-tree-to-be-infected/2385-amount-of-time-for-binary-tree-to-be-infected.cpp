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

    int burnTheTree(TreeNode* targetNode , unordered_map<TreeNode* , TreeNode*>& parentMap ){
        unordered_map<TreeNode* , bool> isBurnt;
        queue<TreeNode*> q ;

        int time = 0 ;

        q.push(targetNode);
        isBurnt[targetNode] = true;

        while(!q.empty()){
            int qSize = q.size();
            bool isFireSpreaded = false;
            for(int i = 0 ; i < qSize ; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> left && !isBurnt[temp -> left]){
                    q.push(temp -> left);
                    isBurnt[temp -> left] = true ;
                    isFireSpreaded = true ; 
                    // make this true as now fire is spread thus it will help in increasing time 
                }

                if(temp -> right && !isBurnt[temp -> right]){
                    q.push(temp -> right);
                    isBurnt[temp -> right] = true ;
                    isFireSpreaded = true ;
                }

                if(parentMap[temp] && !isBurnt[parentMap[temp]]){
                    q.push(parentMap[temp]);
                    isBurnt[parentMap[temp]] = true ;
                    isFireSpreaded = true ;
                }
            }

            if(isFireSpreaded) time++;
        }
       
        return time;
    }

    TreeNode* makeNodeToParentMappingAndFindTargetNode(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parentMap , int target){
        TreeNode* targetNode = nullptr ; // start node of buniing
        queue<TreeNode*> q ;
        q.push(root);
        parentMap[root] = nullptr; // root has no parent thus nullptr
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp -> val == target){
                targetNode = temp ;
            }

            if(temp -> left){
                // connect parent and this node 
                parentMap[temp -> left] = temp;
                q.push(temp -> left);
            }
            if(temp -> right){
                // connect parent and this node
                parentMap[temp -> right] = temp ;
                q.push(temp -> right);
            }
        }

        return targetNode; 
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> parentMap ; 
        TreeNode* targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMap , start);
        return burnTheTree(targetNode , parentMap);
    }
};