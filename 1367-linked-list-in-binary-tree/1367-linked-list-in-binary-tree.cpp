/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool checkIfPresent(ListNode* head, TreeNode* root){
        if(head == nullptr) return true ;
        if(root == nullptr) return false ;

        if(root -> val != head -> val) return false ;

        bool leftCheck = checkIfPresent(head -> next , root -> left);
        bool rightCheck = checkIfPresent(head -> next , root -> right);

        return leftCheck || rightCheck ;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr) return false ;

        // check if LL formed from current node 
        bool isSubPathCurr = checkIfPresent(head , root);

        // check if LL can be found in left 
        bool searchLeftPart = isSubPath(head , root -> left);

        // check if LL can be fround in right 
        bool searchRightPart = isSubPath(head , root -> right);

        return isSubPathCurr || searchLeftPart || searchRightPart ;
    }
};