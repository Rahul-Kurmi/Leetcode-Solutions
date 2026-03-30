/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createChildParentMap(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& mp){
        queue<TreeNode*>q ;
        q.push(root);
        mp[root] = nullptr ;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left) {
                mp[temp->left] = temp;
                q.push(temp->left);
            }

            if (temp->right) {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> mp;
        createChildParentMap(root , mp);
        queue<TreeNode* > q ;
        q.push(target);
        unordered_set<TreeNode* > st ;
        st.insert(target);
        while(!q.empty()){
            int qSize = q.size();
            if(k == 0) break ;
            for(int i = 0 ; i < qSize ; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> left && st.find(temp -> left) == st.end()){
                    q.push(temp -> left);
                    st.insert(temp -> left);
                }

                if(temp -> right && st.find(temp -> right) == st.end()){
                    q.push(temp -> right);
                    st.insert(temp -> right);
                }

                if(mp[temp] && st.find(mp[temp]) == st.end()){
                    q.push(mp[temp]);
                    st.insert(mp[temp]);
                }
            }
            k-- ;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans ;
    }
};